/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:45:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/05 18:16:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_line(t_line line, t_mlx *mlx, int color)
{
	t_pt variance;

	variance.x = (line.dx < 0) ? -1 : 1;
	variance.y = (line.dy < 0) ? -1 : 1;
	if (line.dx == 0 && line.dy == 0)
		ft_draw_pixel(mlx, color, line.start);
	else if (line.dx == 0)
		ft_draw_horizontal(line, mlx, color);
	else if (line.dy == 0)
		ft_draw_vertical(line, mlx, color);
	else
		ft_draw_basenham(line, mlx, color);
}
