/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:45:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/06 13:34:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_horizontal(t_line line, t_mlx *mlx, int variance, int color)
{
	while (line.start.x <= line.end.x)
	{
		ft_draw_pixel(mlx, color, line.start);
		line.start.x += variance;
	}
}

void	ft_draw_vertical(t_line line, t_mlx *mlx, int variance, int color)
{
	while (line.start.y <= line.end.y)
	{
/*		ft_putstr("\nyolo\nx :");
		ft_putnbr(line.start.x);
		ft_putstr("\ny :");
		ft_putnbr(line.start.y);
*/		ft_draw_pixel(mlx, color, line.start);
		line.start.y += variance;
	}
		ft_putstr("\nfinal\nx :");
		ft_putnbr(line.end.x);
		ft_putstr("\ny :");
		ft_putnbr(line.end.y);
}

void	ft_draw_line(t_line line, t_mlx *mlx, int color)
{
	t_pt variance;

	variance.x = (line.dx < 0) ? -1 : 1;
	variance.y = (line.dy < 0) ? -1 : 1;
	if (line.dx == 0 && line.dy == 0)
		ft_draw_pixel(mlx, color, line.start);
	else if (line.dy == 0)
		ft_draw_horizontal(line, mlx, variance.y, color);
	else if (line.dx == 0)
		ft_draw_vertical(line, mlx, variance.x, color);
//	else
//		ft_draw_basenham(line, mlx, variance, color);
}
