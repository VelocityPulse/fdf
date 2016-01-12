/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:08:16 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/12 13:49:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_area	ft_draw_make_area(t_pt a, t_pt b, t_pt c, t_pt d)
{
	t_area area;

	area.a.x = a.x;
	area.a.y = a.y;
	area.b.x = b.x;
	area.b.y = b.y;
	area.c.x = c.x;
	area.c.y = c.y;
	area.d.x = d.x;
	area.d.y = d.y;
	return (area);
}
