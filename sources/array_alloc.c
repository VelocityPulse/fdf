/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:30:41 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/22 22:59:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_array_alloc(const int nbr_line)
{
	t_array		*array;

	array = (t_array*)malloc(sizeof(t_array));
	array->tab = (int **)ft_memalloc(sizeof(int *) * nbr_line);
	array->pts = NULL;
	array->size.x = 0;
	array->size.y = 0;
	return (array);
}

t_array		*ft_free_array(t_array *array)
{
	int		i;

	i = 0;
	if (!array)
		return (NULL);
	while (i <= array->size.y)
		ft_memdel((void **)&array->tab[i++]);
	ft_memdel((void **)array->tab);
	ft_memdel((void **)&array->pts);
	ft_memdel((void **)&array);
	return (array);
}
