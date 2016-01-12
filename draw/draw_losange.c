/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/12 09:49:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft__draw_losange(t_area losange, t_mlx *mlx, int color)
{
	color = 1;
	ft_draw_line(ft_draw_make_line(a.x, a.y, b.x, b.y), mlx, (int)0xff0000);
	ft_draw_line(ft_draw_make_line(b.x, b.y, c.x, c.y), mlx, (int)0x00ff00);
	ft_draw_line(ft_draw_make_line(c.x, c.y, d.x, d.y), mlx, (int)0x0000ff);
	ft_draw_line(ft_draw_make_line(d.x, d.y, a.x, a.y), mlx, (int)0xffffff);

//	ft_draw_line(ft_draw_make_line(d.x, d.y, b.x, b.y), mlx, (int)0x00ffff);
}

void	ft_draw_make_losange(t_line line, int mediane, t_mlx *mlx, int color)
{
	t_pt	intersection;
	t_area	losange;
	int		ao;
	float	coef;

	intersection.x = (line.start.x + line.end.x) / 2;
	intersection.y = (line.start.y + line.end.y) / 2;
	ao = sqrtf((line.dx / 2) * (line.dx / 2) + ((line.dy / 2) * (line.dy / 2)));
	if (ao > (float)mediane)
		coef = (float)(ao / (float)mediane);
	else
	{
		coef = (float)((float)mediane / ao);
		coef = 1 / coef;
	}
/**
*	printf("coordonnee A : %d;%d\n", line.start.x, line.start.y);
*	printf("coordonnee C : %d;%d\n", line.end.x, line.end.y);
*	printf("longueur AO : %d\n", ao);
*	printf("coeficien proportionnel : %f\n", coef);
**/
	losange.a.x = line.start.x;
	losange.a.y = line.start.y;
	losange.c.x = line.end.x;
	losange.c.y = line.end.y;
	losange.d.x = intersection.x - (int)((float)(line.dy / 2) / coef);
	losange.d.y = intersection.y + (int)((float)(line.dx / 2) / coef);
	losange.b.x = intersection.x + (int)((float)(line.dy / 2) / coef);
	losange.b.y = intersection.y - (int)((float)(line.dx / 2) / coef);
	ft__draw_losange(losange, mlx, color);
}

