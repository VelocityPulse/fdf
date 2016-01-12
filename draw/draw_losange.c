/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/12 15:38:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_losange(t_area l, t_mlx *mlx, int color)
{
	ft_draw_line(ft_draw_make_line(l.a.x, l.a.y, l.b.x, l.b.y), mlx, color);
	ft_draw_line(ft_draw_make_line(l.b.x, l.b.y, l.c.x, l.c.y), mlx, color);
	ft_draw_line(ft_draw_make_line(l.c.x, l.c.y, l.d.x, l.d.y), mlx, color);
	ft_draw_line(ft_draw_make_line(l.d.x, l.d.y, l.a.x, l.a.y), mlx, color);
}

t_area	ft_draw_make_losange(t_line line, int mediane)
{
	t_pt	intersection;
	t_area	losange;
	int		ao;
	float	coef;

	intersection.x = (line.start.x + line.end.x) / 2;
	intersection.y = (line.start.y + line.end.y) / 2;
	ao = sqrtf((line.dx / 2) * (line.dx / 2) + (line.dy / 2) * (line.dy / 2));
	if (ao > (float)mediane)
		coef = (float)(ao / (float)mediane);
	else
	{
		coef = (float)((float)mediane / ao);
		coef = 1 / coef;
	}
	losange.a.x = line.start.x;
	losange.a.y = line.start.y;
	losange.c.x = line.end.x;
	losange.c.y = line.end.y;
	losange.d.x = intersection.x - (int)((float)(line.dy / 2) / coef);
	losange.d.y = intersection.y + (int)((float)(line.dx / 2) / coef);
	losange.b.x = intersection.x + (int)((float)(line.dy / 2) / coef);
	losange.b.y = intersection.y - (int)((float)(line.dx / 2) / coef);
	return (losange);
}

/**
 *	printf("coordonnee A : %d;%d\n", line.start.x, line.start.y);
 *	printf("coordonnee C : %d;%d\n", line.end.x, line.end.y);
 *	printf("longueur AO : %d\n", ao);
 *	printf("coeficien proportionnel : %f\n", coef);
 **/
