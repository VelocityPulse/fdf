/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/13 22:26:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_to_array(char **tab, int nbr_line)
{
	t_array		*array;
	char		**tab_values;
	int 		i;
	int			i2;
	int			cpt;

	i = -1;
	array = (t_array *)malloc(sizeof(t_array));
	array->tab = (int **)ft_memalloc(sizeof(int *) * nbr_line);
	array->size.y = nbr_line;
	while (++i <= nbr_line)
	{
		tab_values = ft_strsplit(tab[i], ' ');
		cpt = 0;
		while (tab_values[cpt])
			cpt++;
		array->tab[i] = (int *)ft_memalloc(sizeof(int) * (cpt + 1));
		i2 = -1;
		while (tab_values[++i2])
			array->tab[i][i2] = ft_atoi(tab_values[i2]);
		i2++;
		while (tab_values[--i2])
			ft_memdel((void **)&tab_values[i2]);
		ft_memdel((void **)tab_values);
	}
	return (array);
}
