#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/01/23 00:01:04 by                   #+#    #+#             *#
#*   Updated: 2016/01/23 00:43:02 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME =			draw.a

SRCS =			./draw_pixel.c \
				./new_image.c \
				./mlx_init.c \
				./draw_make_line.c \
				./draw_line.c \
				./draw_make_area.c \
				./draw_rect.c \
				./draw_make_losange.c \
				./draw_losange.c \
				./draw_make_isocele.c \
				./draw_isocele.c \
				./draw_make_matrix.c \
				./draw_make_pt.c \
				./draw_make_vector.c \
				./draw_add_vector.c

OBJS =			./draw_pixel.o \
				./new_image.o \
				./mlx_init.o \
				./draw_make_line.o \
				./draw_line.o \
				./draw_make_area.o \
				./draw_rect.o \
				./draw_make_losange.o \
				./draw_losange.o \
				./draw_make_isocele.o \
				./draw_isocele.o \
				./draw_make_matrix.o \
				./draw_make_pt.o \
				./draw_make_vector.o \
				./draw_add_vector.o

FRAMEWORK =		-framework OpenGL -framework AppKit

FLAGS = 		-Wall -Wextra -Werror

CC =			gcc

RM =			rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all
