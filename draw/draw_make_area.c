/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:08:16 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/08 17:08:27 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_area	ft_draw_make_area(int x1, int y1, int x2, int y2)
{
	t_area area;

	area.start.x = x1;
	area.start.y = y1;
	area.end.x = x2;
	area.end.y = y2;
	return (area);
}
