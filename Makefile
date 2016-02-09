#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/26 15:16:47 by                   #+#    #+#             *#
#*   Updated: 2016/02/08 23:47:14 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			fdf

MAINTEST =		./maintest/main.c

SRC =			./sources/main.c \
				./sources/array_alloc.c \
				./sources/convert_array_to_pts.c \
				./sources/convert_to_array.c \
				./sources/fdf.c \
				./sources/get_array.c \
				./sources/get_next_line.c \
				./sources/list_gline.c \
				./sources/edit_rad.c \
				./sources/init_info.c \
				./sources/exit_fdf.c \
				./sources/edit_pos.c \
				./sources/edit_scale.c \
				./sources/edit_reset.c \
				./sources/fdf_pt3d_alloc.c \
				./sources/fdf_add_pos.c \
				./sources/fdf_add_scale.c \
				./sources/fdf_pt_alloc.c \
				./sources/fdf_draw.c

OBJS =			./main.o \
				./array_alloc.o \
				./convert_array_to_pts.o \
				./convert_to_array.o \
				./fdf.o \
				./get_array.o \
				./get_next_line.o \
				./list_gline.o \
				./edit_rad.o \
				./init_info.o \
				./exit_fdf.o \
				./edit_pos.o \
				./edit_scale.o \
				./edit_reset.o \
				./fdf_pt3d_alloc.o \
				./fdf_pt_alloc.o \
				./fdf_add_pos.o \
				./fdf_add_scale.o \
				./fdf_draw.o

DRAW =			./draw/draw.a

LIBFT =			./libft/libft.a

LIBMLX =		./libmlx/libmlx.a

LMLX =			#-lmlx

FRAMEWORK =		$(LMLX) -framework OpenGL -framework AppKit

FLAGS =			-Wall -Wextra -Werror -fsanitize=address

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(DRAW) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBFT) $(LIBMLX) $(DRAW) -o $(NAME)

$(OBJS): $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(SRC)

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./libmlx/

$(DRAW):
	make -C ./draw/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/
#	make clean -C ./libmlx/
	make clean -C ./draw/

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX) $(DRAW)

re: fclean all

test: $(LIBFT) $(LIBMLX) $(DRAW)
	$(CC) $(FLAGS) -c $(MAINTEST)
	$(CC) $(FLAGS) $(FRAMEWORK) main.o $(LIBFT) $(LIBMLX) $(DRAW)
	$(RM) main.o
	make fclean

