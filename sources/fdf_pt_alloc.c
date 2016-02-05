/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pt_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:35:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 12:02:35 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_pt		**ft_fdf_pt_alloc(t_array *a)
{
	t_pt	**pt;
	int		i;

	i = -1;
	pt = (t_pt **)ft_memalloc(sizeof(t_pt *) * (a->max_size.y + 1));
	while (++i <= a->max_size.y)
		pt[i] = (t_pt *)ft_memalloc(sizeof(t_pt) * (a->size_x[i] + 1));
	return (pt);
}

t_pt		**ft_fdf_free_pt(t_array *a)
{
	int		size;

	size = a->max_size.y + 1;
	if (!a->tab_pts)
		return (NULL);
	while (--size)
		ft_memdel((void **)&a->layout_pts[size]);
	ft_memdel((void **)a->layout_pts);
	return (NULL);
}
