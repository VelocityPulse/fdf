/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_color_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:32:21 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/06 13:04:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_horizontal_c(t_line l, t_mlx *mlx, int var, t_color c)
{
	int		color;
	int		increment;

	increment = (l.dx + l.dy) + (c.c1 - c.c2);
	color = c.c1;
	while (l.start.x != l.end.x)
	{
		ft_draw_pixel(mlx, color, l.start);
		l.start.x += var;
		color = increment;
	}
}

void	ft_draw_color_line(t_line l, t_mlx *mlx, int c1, int c2)
{
	t_pt		variance;
	t_color		c;

	c.c1 = c1;
	c.c2 = c2;
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
