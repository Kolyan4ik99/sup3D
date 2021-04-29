FLAGS = -Wall -Wextra -Werror

NAME = cub3D

SRC_DIR = ./src/
I = -I./includes/

HEADER = ./includes/cub3d.h

SRC_FILES = actions.c \
            bubble_sort.c \
            check_parser.c \
            close_img.c \
            dda.c \
            draw.c \
            draw_ceil_floor.c \
            errors.c \
            ../gnl/get_next_line.c \
            ../gnl/get_next_line_utils.c \
            fill_map.c \
            fill_plr.c \
            fill_re_c_f.c \
            fill_texture.c \
            init_tex.c \
            main.c \
            make_bitmap.c \
            parser.c \
            sprite.c \
            turns.c

SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}
OBJS = ${SRCS:.c=.o}

FRAME = -framework OpenGL -framework AppKit

${NAME}: ${OBJS} libft.a libmlx.a
	gcc ${FRAME} ${OBJS} ./libft/libft.a ./mlx/libmlx.a -o ${NAME}

libft.a:
	make -C ./libft/

libmlx.a:
	make -C ./mlx/

all: ${NAME}

%.o: %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@ ${I}

clean:
	make clean -C ./libft/
	make clean -C ./mlx/
	${RM} ${OBJS} ./libft/*.o

fclean: clean
	rm -f ${NAME} ./libft/libft.a ./mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re