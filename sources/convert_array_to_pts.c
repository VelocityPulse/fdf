/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_to_pts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:47:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/25 14:03:30 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_array_to_pts(t_array *a)
{
	t_pt	p;
	t_pt	middle;

	p.y = 0;
	middle = ft_make_pt(a->size.x / 2, a->size.y / 2);
	a->tab_pts = ft_pt3d_alloc(a->size);
	printf("size.x :%d\nsize.y :%d\n", a->size.x, a->size.y);
	while (p.y <= a->size.y)
	{
		printf("\np.x :%d\np.y :%d", p.x, p.y);
		p.x = 0;
		YOLO1
		while (p.x <= a->size.x)
		{
			YOLO2
			a->tab_pts[p.y][p.x].x = p.x - middle.x;
			a->tab_pts[p.y][p.x].y = p.y - middle.y;
			a->tab_pts[p.y][p.x].z = a->tab[p.y][p.x];
			p.x++;
		}
		p.y++;
	}
	TEST
	return (a);
}
