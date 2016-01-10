/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/10 16:20:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_draw_losange(t_pt a, t_pt c, t_pt b, t_pt d, t_mlx *mlx, int color)
{
	color = 1;
	ft_draw_line(ft_draw_make_line(a.x, a.y, b.x, b.y), mlx, (int)0xff0000);
	ft_draw_line(ft_draw_make_line(b.x, b.y, c.x, c.y), mlx, (int)0x00ff00);
	ft_draw_line(ft_draw_make_line(c.x, c.y, d.x, d.y), mlx, (int)0x0000ff);
	ft_draw_line(ft_draw_make_line(d.x, d.y, a.x, a.y), mlx, (int)0xffffff);

	ft_draw_line(ft_draw_make_line(d.x, d.y, b.x, b.y), mlx, (int)0x00ffff);
}

#include <stdio.h>

void	ft_draw_losange(t_area area, int mediane, t_mlx *mlx, int color)
{
	t_pt	intersection;
	t_pt	d;
	t_pt	b;
	float	a;

	intersection.x = (area.start.x + area.end.x) / 2;
	intersection.y = (area.start.y + area.end.y) / 2;
	a = 1 / ((float)(area.end.x - area.start.x) / (float)(area.end.y - area.start.y));
	ft_draw_line(ft_draw_make_line(area.start.x, area.start.y, area.end.x, area.end.y), mlx,
	(int)0xffff00);

	mediane = 10;
	
	printf("coordonnee de A : %f\n", ((float)mediane * a));
	d.x = intersection.x - (mediane * (int)a);
	d.y = intersection.y - (mediane * (int)a);

	d.x = ((area.start.x + intersection.x) - mediane / 2) / 2;
	d.y = ((area.end.y + intersection.y) + mediane / 2) / 2;
	b.x = ((area.end.x + intersection.x) + mediane / 2) / 2;
	b.y = ((area.start.y + intersection.y) - mediane / 2) / 2;


	ft_draw_draw_losange(area.start, area.end, b, d, mlx, color);
}

