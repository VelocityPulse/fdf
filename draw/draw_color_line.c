/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:32:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/07 14:40:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_horizontal_c(t_line l, t_mlx *mlx, int var, t_dual_color c)
{
	t_rgb	d;
	int		n;
	int		x;

	n = l.dx + l.dy;
	x = 0;
	while (l.start.x != l.end.x)
	{
		x++;
		d.r = c.c1.r + (int)(((float)(c.c2.r - c.c1.r) / (float)n) * (float)x);
		d.g = c.c1.g + (int)(((float)(c.c2.g - c.c1.g) / (float)n) * (float)x);
		d.b = c.c1.b + (int)(((float)(c.c2.b - c.c1.b) / (float)n) * (float)x);
		ft_draw_pixel(mlx, ft_get_hexa(d), l.start);
		l.start.x += var;
	}
}

void	ft_draw_color_line(t_line l, t_mlx *mlx, int c1, int c2)
{
	t_pt			variance;
	t_dual_color	c;

	c.c1 = ft_get_rgb(c1);
	c.c2 = ft_get_rgb(c2);
	variance.x = (l.dx < 0) ? -1 : 1;
	variance.y = (l.dy < 0) ? -1 : 1;
	if (l.dx == 0 && l.dy == 0)
		ft_draw_pixel(mlx, c1, l.start);
	else if (l.dy == 0)
		ft_draw_horizontal_c(l, mlx, variance.x, c);
/*	else if (l.dx == 0)
		ft_draw_vertical_c(l, mlx, variance.y, c);
	else
		ft_draw_bresenham_c(l, mlx, variance, c);
*/
}
