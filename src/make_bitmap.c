/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 04:16:34 by cclock            #+#    #+#             */
/*   Updated: 2021/04/27 04:16:37 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			file_type_data(t_all *all, int fd)
{
	int				i;
	unsigned char	bmp_header[14];

	i = 0;
	while (i < 14)
		bmp_header[i++] = (unsigned char)(0);
	bmp_header[0] = (unsigned char)('B');
	bmp_header[1] = (unsigned char)('M');
	i = all->tex.r.height * all->tex.r.width * all->win.bpp / 8 + 54;
	bmp_header[2] = (unsigned char)(i);
	bmp_header[3] = (unsigned char)(i >> 8);
	bmp_header[4] = (unsigned char)(i >> 16);
	bmp_header[5] = (unsigned char)(i >> 24);
	bmp_header[10] = (unsigned char)(54);
	write(fd, bmp_header, 14);
}

static void			img_info_data(t_all *all, int fd)
{
	int				i;
	unsigned char	bmp_header[40];

	i = 0;
	while (i < 40)
		bmp_header[i++] = (unsigned char)(0);
	bmp_header[0] = (unsigned char)(40);
	i = all->tex.r.width;
	bmp_header[4] = (unsigned char)(i);
	bmp_header[5] = (unsigned char)(i >> 8);
	bmp_header[6] = (unsigned char)(i >> 16);
	bmp_header[7] = (unsigned char)(i >> 24);
	i = all->tex.r.height;
	bmp_header[8] = (unsigned char)(i);
	bmp_header[9] = (unsigned char)(i >> 8);
	bmp_header[10] = (unsigned char)(i >> 16);
	bmp_header[11] = (unsigned char)(i >> 24);
	bmp_header[12] = (unsigned char)(1);
	bmp_header[14] = (unsigned char)32;
	write(fd, bmp_header, 40);
}

static void			pixel_data(t_all *all, int fd)
{
	int				i;
	int				j;
	unsigned int	*dst;

	i = all->tex.r.height;
	while (i >= 0)
	{
		j = 0;
		while (j < all->tex.r.width)
		{
			dst = (unsigned int *)(all->win.addr + (i * all->win.line_l +
													j * (all->win.bpp / 8)));
			write(fd, dst, 4);
			j++;
		}
		i--;
	}
}

int					create_bmp_file(t_all *all)
{
	int				fd;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		return (0);
	file_type_data(all, fd);
	img_info_data(all, fd);
	pixel_data(all, fd);
	close(fd);
	return (1);
}

int					create_bitmap(t_all *all)
{
	if (draw_frame(all, 0) < 0)
		ft_exit("Error\n");
	if (create_bmp_file(all) == 0)
	{
		mlx_destroy_image(all->win.mlx, all->win.img);
		exit(0);
	}
	mlx_destroy_image(all->win.mlx, all->win.img);
	exit(0);
}
