/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclock <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:06:33 by cclock            #+#    #+#             */
/*   Updated: 2021/03/03 12:06:35 by cclock           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			start_mlx(t_all *all, int point)
{
	all->win.mlx = mlx_init();
	if (point)
		all->win.win = mlx_new_window(all->win.mlx,
			all->tex.r.width, all->tex.r.height, "Cub3D");
	all->win.img = mlx_new_image(all->win.mlx,
						all->tex.r.width, all->tex.r.height);
	if (!all->win.img)
		return (-1);
	all->win.addr = mlx_get_data_addr(all->win.img,
							&all->win.bpp, &all->win.line_l, &all->win.en);
	if (init_tex(all) < 0)
		ft_exit("Error\nBad xpm file\n");
	if (!all->win.addr)
		return (-1);
	return (1);
}

void		start_srct(t_all *all)
{
	all->plr.dir_y = 0;
	all->plr.dir_x = -1;
	all->plr.plane_y = 0.66;
	all->plr.plane_x = 0;
	all->head = NULL;
	all->flag.ea_det = 0;
	all->flag.we_det = 0;
	all->flag.no_det = 0;
	all->flag.so_det = 0;
	all->flag.s_det = 0;
	all->flag.map_det = 0;
	all->flag.res_det = 0;
	all->flag.c_det = 0;
	all->flag.f_det = 0;
	all->flag.move_a = 0;
	all->flag.move_d = 0;
	all->flag.move_w = 0;
	all->flag.move_s = 0;
	all->flag.rot_l = 0;
	all->flag.rot_r = 0;
}

void		hook_catch(t_all *all)
{
	mlx_hook(all->win.win, 2, 0, key_prs, all);
	mlx_hook(all->win.win, 3, 0, key_rls, all);
	mlx_hook(all->win.win, 17, 0, key_close, all);
	mlx_loop_hook(all->win.mlx, inits_keys, all);
}

int			ft_strcmp(char *str, char *ptr)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] != ptr[i])
			return (0);
		++i;
	}
	if (ptr[i])
		return (0);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_all	all;

	start_srct(&all);
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 1)
	{
		if (ft_strcmp(ft_strchr(argv[1], '.'), ".cub") != 1)
			ft_exit("Bad map\n");
		parse(&all, argv[1]);
		check_all(&all);
		if (start_mlx(&all, 0) < 0)
			return (ft_exit("Ошибка запуска mlx"));
		create_bitmap(&all);
	}
	else if (argc == 2 && ft_strcmp(ft_strchr(argv[1], '.'), ".cub") == 1)
	{
		parse(&all, argv[1]);
		check_all(&all);
		if (start_mlx(&all, 1) < 0)
			return (ft_exit("Ошибка запуска mlx"));
		hook_catch(&all);
		(draw_frame(&all, 1) < 0) ? ft_exit("Error") : 0;
		mlx_loop(all.win.mlx);
	}
	ft_exit("Error");
	return (0);
}
