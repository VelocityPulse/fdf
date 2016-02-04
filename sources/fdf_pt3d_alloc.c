/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    fdf_pt3d_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:37:05 by                   #+#    #+#             */
/*   Updated: 2016/02/04 17:57:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_pt3d		**ft_fdf_pt3d_alloc(t_array *a)
{
	t_pt3d		**pt;
	int			i;

	i = -1;
	pt = (t_pt3d **)ft_memalloc(sizeof(t_pt3d *) * (a->max_size.y + 1));
	while (++i <= a->max_size.y)
		pt[i] = (t_pt3d *)ft_memalloc(sizeof(t_pt3d) * (a->size_x[i] + 1));
	return (pt);
}

t_pt3d		**ft_fdf_free_pt3d(t_array *a)
{
	int		size;

	size = a->max_size.y + 1;
	if (!a->tab_pts)
		return (NULL);
	while (--size)
		ft_memdel((void **)&a->tab_pts[size]);
	ft_memdel((void **)a->tab_pts);
	return (NULL);
}
