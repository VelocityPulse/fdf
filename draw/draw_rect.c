/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:33:08 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/08 13:58:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_rect(t_area area, t_mlx *mlx, int color)
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	x1 = area.start.x;
	y1 = area.start.y;
	x2 = area.end.x;
	y2 = area.end.y;
	ft_draw_line(ft_draw_make_line(x1, y1, x2, y1), mlx, color);
	ft_draw_line(ft_draw_make_line(x1, y1, x1, y2), mlx, color);
	ft_draw_line(ft_draw_make_line(x2, y2, x1, y2), mlx, color);
	ft_draw_line(ft_draw_make_line(x2, y2, x2, y1), mlx, color);
}
