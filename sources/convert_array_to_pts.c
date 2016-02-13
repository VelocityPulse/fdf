/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_to_pts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:04:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/13 12:39:15 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_theoric_z(t_array *a)
{
	a->min_z = a->min_z < 0 ? -a->min_z : a->min_z;
	a->max_z = a->max_z < 0 ? -a->max_z : a->max_z;
	if (a->min_z == 0 && a->max_z == 0)
		a->theoric_z = 1;
	else
		a->theoric_z = a->min_z + a->max_z;
}

t_array		*ft_convert_array_to_pts(t_array *a)
{
	t_pt	p;
	t_pt	middle;

	middle = ft_make_pt(a->max_size.x / 2, a->max_size.y / 2);
	if (!a->tab_pts)
		a->tab_pts = ft_fdf_pt3d_alloc(a);
	p.y = 0;
	while (p.y <= a->max_size.y)
	{
		p.x = 0;
		while (p.x <= a->size_x[p.y])
		{
			a->tab_pts[p.y][p.x].x = p.x - middle.x;
			a->tab_pts[p.y][p.x].y = p.y - middle.y;
			a->tab_pts[p.y][p.x].z = a->tab[p.y][p.x];
			if (a->tab[p.y][p.x] > a->max_z)
				a->max_z = a->tab[p.y][p.x];
			else if (a->tab[p.y][p.x] < a->min_z)
				a->min_z = a->tab[p.y][p.x];
			p.x++;
		}
		p.y++;
	}
	ft_theoric_z(a);
	return (a);
}
