/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_add_scale.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:26:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 13:28:22 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf_add_scale(t_array *a, t_pt3d scale)
{
	t_pt	p;

	p.y = 0;
	while (p.y <= a->max_size.y)
	{
		p.x = 0;
		while (p.x <= a->size_x[p.y])
		{
			a->tab_pts[p.y][p.x].x *= scale.x;
			a->tab_pts[p.y][p.x].y *= scale.y;
			a->tab_pts[p.y][p.x].z *= scale.z;
			p.x++;
		}
		p.y++;
	}
}
