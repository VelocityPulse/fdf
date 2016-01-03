* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/26 15:16:47 by                   #+#    #+#             *#
#*   Updated: 2016/01/03 12:53:20 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fdf

SRC = ./sources/

OBJS = ./sources/

LIBFT = ./libft/libft.a

LIBMLX = ./libmlx/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(FLAGS) $(FRAMEWORK) $(OBJS) $(LIBT) $(LIBMLX)

$(OBJS): $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(LIBFT)

$(LIBFT):
	make -C ./libft/

$(LIBMLX):
	make -C ./libmlx/

clean:
	$(RM) $(OBJS)
	make fclean -C ./libft/
	make fclean -C ./libmlx/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft/
	make fclean -C ./libmlx/

re: fclean all
