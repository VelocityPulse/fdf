/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_add_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:43:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 11:47:45 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf_add_pos(t_array *a, t_pt pos)
{
	t_pt p;

	p.y = 0;
	while (p.y <= a->max_size.y)
	{
		p.x = 0;
		while (p.x <= a->size_x[p.y])
		{
			a->layout_pts[p.y][p.x].x += pos.x;
			a->layout_pts[p.y][p.x].y += pos.y;
		}
		p.y++;
	}
}
