/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:45:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/25 16:11:01 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_horizontal(t_line line, t_mlx *mlx, int variance, int color)
{
	while (line.start.x != line.end.x)
	{
		ft_draw_pixel(mlx, color, line.start);
		line.start.x += variance;
	}
}

void	ft_draw_vertical(t_line line, t_mlx *mlx, int variance, int color)
{
	while (line.start.y != line.end.y)
	{
		ft_draw_pixel(mlx, color, line.start);
		line.start.y += variance;
	}
}

void	ft_draw_bresenham(t_line line, t_mlx *mlx, int color, t_pt variance)
{
	int		err;
	
	if (line.dx < 0)
		line.dx = -line.dx;
	if (line.dy < 0)
		line.dy = -line.dy;
	err = -line.dx>>1; // -(dx / 2)
	while (line.start.x != line.end.x)
	{
		ft_draw_pixel(mlx, color, line.start);
		err += line.dy;
		while (err > 0)
		{
			ft_draw_pixel(mlx, color, line.start);
			err -= line.dx;
			line.start.y += variance.y;
		}
		line.start.x += variance.x;
	}
}
void	ft_draw_line(t_line line, t_mlx *mlx, int color)
{
	t_pt variance;

	variance.x = (line.dx < 0) ? -1 : 1;
	variance.y = (line.dy < 0) ? -1 : 1;
	if (line.dx == 0 && line.dy == 0)
		ft_draw_pixel(mlx, color, line.start);
	else if (line.dy == 0)
		ft_draw_horizontal(line, mlx, variance.x, color);
	else if (line.dx == 0)
		ft_draw_vertical(line, mlx, variance.y, color);
	else
		ft_draw_bresenham(line, mlx, color, variance);
}
