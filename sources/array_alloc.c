/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:30:41 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/24 21:44:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_array_alloc(const int nbr_line)
{
	t_array		*array;

	array = (t_array *)malloc(sizeof(t_array));
	array->tab = (int **)ft_memalloc(sizeof(int *) * nbr_line);
	array->tab_pts = NULL;
	array->layout_pts = NULL;
	array->size.x = 0;
	array->size.y = 0;
	return (array);
}

t_array		*ft_free_array(t_array *array)
{
	int		i;

	if (!array && !(i = 0))
		return (NULL);
	if (array->tab)
	{
		while (i <= array->size.y)
			ft_memdel((void **)&array->tab[i++]);
	}
	ft_memdel((void **)array->tab);
	array->tab_pts = ft_free_pt3d(array->tab_pts, array->size.y);
	array->layout_pts = ft_free_pt(array->layout_pts, array->size.y);
	ft_memdel((void **)&array);
	return (array);
}
