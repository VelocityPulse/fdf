#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/26 15:16:47 by                   #+#    #+#             *#
#*   Updated: 2016/01/07 23:16:56 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			fdf

SRC =			./sources/main.c

DRAW =			./draw/draw_pixel.c \
				./draw/new_image.c \
				./draw/mlx_init.c \
				./draw/draw_make_line.c \
				./draw/draw_line.c \
				./draw/draw_make_area.c \
				./draw/draw_rect.c

OBJS =			./main.o \
				./draw_pixel.o \
				./new_image.o \
				./mlx_init.o \
				./draw_make_line.o \
				./draw_line.o \
				./draw_make_area.o \
				./draw_rect.o

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			-lmlx

FRAMEWORK =		$(LMLX) -framework OpenGL -framework AppKit

FLAGS =			-Wall -Wextra -Werror

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) -c $(SRC) $(DRAW)

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./libmlx/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/
	make clean -C ./libmlx/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all
