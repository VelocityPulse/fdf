#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/26 15:16:47 by                   #+#    #+#             *#
#*   Updated: 2016/01/22 23:50:33 by                  ###   ########.fr       *#
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
				./draw/draw_rect.c \
				./draw/draw_losange.c \
				./draw/draw_make_losange.c \
				./draw/draw_isocele.c \
				./draw/draw_make_isocele.c \
				./draw/draw_make_matrix.c \
				./draw/draw_make_pt.c \
				./draw/draw_make_vector.c \
				./draw/draw_add_vector.c

OBJS =			./main.o \
				./draw_pixel.o \
				./new_image.o \
				./mlx_init.o \
				./draw_make_line.o \
				./draw_line.o \
				./draw_make_area.o \
				./draw_rect.o \
				./draw_losange.o \
				./draw_make_losange.o \
				./draw_isocele.o \
				./draw_make_isocele.o \
				./draw_make_matrix.o \
				./draw_make_pt.o \
				./draw_make_vector.o \
				./draw_add_vector.o

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			#-lmlx

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
