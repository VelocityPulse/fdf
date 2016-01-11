/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/11 15:07:24 by                  ###   ########.fr       */
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

void	ft_draw_losange(t_line line, int mediane, t_mlx *mlx, int color)
{
	t_pt	intersection;
	t_pt	d;
	t_pt	b;
	int		ao;
	float	coef;

	intersection.x = (line.start.x + line.end.x) / 2;
	intersection.y = (line.start.y + line.end.y) / 2;
	

	ft_draw_line(ft_draw_make_line(line.start.x, line.start.y, line.end.x, line.end.y), mlx,
	(int)0xffff00);

	mediane = 10;
	ao = sqrtf((line.dx / 2) * (line.dx / 2) + ((line.dy / 2) * (line.dy / 2)));
	coef = (float)(ao / mediane);
	
	printf("coordonnee A : %d;%d\n", line.start.x, line.start.y);
	printf("coordonnee C : %d;%d\n", line.end.x, line.end.y);
	printf("longueur AO : %d\n", ao);
	printf("coeficien proportionnel : %f\n", coef);

	d.x = intersection.x - (int)((float)(line.dy / 2) / coef);
	d.y = intersection.y + (int)((float)(line.dx / 2) / coef);
	b.x = intersection.x + (int)((float)(line.dy / 2) / coef);
	b.y = intersection.y - (int)((float)(line.dx / 2) / coef);
	ft_draw_draw_losange(line.start, line.end, b, d, mlx, color);

}

