/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isocele.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:33:59 by                   #+#    #+#             */
/*   Updated: 2016/01/22 23:37:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_area	ft_make_isocele(t_line line, int mediane)
{
	t_pt	intersection;
	t_area	triangle;
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
	triangle.a.x = line.start.x;
	triangle.a.y = line.start.y;
	triangle.b.x = line.end.x;
	triangle.b.y = line.end.y;
	triangle.c.x = intersection.x + (int)((float)(line.dy / 2) / coef);
	triangle.c.y = intersection.y - (int)((float)(line.dx / 2) / coef);
	return (triangle);
}
