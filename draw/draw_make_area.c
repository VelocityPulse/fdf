/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:08:16 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/22 23:33:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_area	ft_make_area(t_pt a, t_pt b, t_pt c, t_pt d)
{
	t_area area;

	area.a = a;
	area.b = b;
	area.c = c;
	area.d = d;
	return (area);
}
