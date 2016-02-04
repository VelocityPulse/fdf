/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:30:41 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/04 18:02:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_array_alloc(const int nbr_line)
{
	t_array		*array;

	array = (t_array *)malloc(sizeof(t_array));
	array->tab = (int **)ft_memalloc(sizeof(int *) * (nbr_line + 1));
	array->tab_pts = NULL;
	array->layout_pts = NULL;
	array->size_x = NULL;
	array->max_size = ft_make_pt(0, 0);
	return (array);
}

t_array		*ft_free_array(t_array *array)
{
	int		i;

	if (!array && !(i = 0))
		return (NULL);
	if (array->tab)
	{
		while (i <= array->max_size.y)
			ft_memdel((void **)&array->tab[i++]);
	}
	ft_memdel((void **)array->tab);
	array->tab_pts = ft_fdf_free_pt3d(array);
	array->layout_pts = ft_free_pt(array->layout_pts, array->max_size.y);
	ft_memdel((void **)&array);
	return (array);
}
