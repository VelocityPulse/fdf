/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array_layout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:31:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/02 12:37:53 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	*ft_array_layout(t_pt3d *pts, int size, t_pt *new_pts, t_matrix t)
{
	int		i;

	i = -1;
	if (!new_pts)
	{
		new_pts = (t_pt *)ft_memalloc(sizeof(t_pt) * (size + 1));
		while (++i <= size)
			new_pts[i] = ft_make_pt(0, 0);
	}
	i = -1;
	

	while (++i <= size)
		new_pts[i] = ft_add_pt(new_pts[i], ft_apply_matrix(pts[i], t));
	return (new_pts);
}

t_pt	ft_add_pt(t_pt pt1, t_pt pt2)
{
	pt1.x += pt2.x;
	pt1.y += pt2.y;
	return (pt1);
}
