/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:03:46 by                   #+#    #+#             */
/*   Updated: 2016/01/06 15:37:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

typedef struct	s_line
{
	t_pt	start;
	t_pt	end;
	int		dx;
	int		dy;
}				t_line;

typedef struct	s_img
{
	char	*data;
	void	*p_img;
	int		width;
	int		bpp;
	int		endian;
	int		max_size;
}				t_img;

typedef struct	s_mlx
{
	void	*p_mlx;
	void	*p_win;
	int		height;
	int		width;
	t_img	*mlx_img;
}				t_mlx;

void	ft_mlx_init(int width, int height, t_mlx *mlx, char *name);
void	ft_new_image(t_mlx *mlx);
void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt);
t_line	ft_draw_make_line(int x1, int y1, int x2, int y2);
void	ft_draw_line(t_line, t_mlx *mlx, int color);
void	ft_draw_horizontal(t_line line, t_mlx *mlx, int variance, int color);
void	ft_draw_vertical(t_line line, t_mlx *mlx, int variane, int color);

#endif
