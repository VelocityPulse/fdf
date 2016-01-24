/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/24 18:31:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_to_array(char **tab, const int nb_line, t_array *a)
{
	t_array		*array;
	char		**tab_values;
	int 		i;
	int			i2;
	int			cpt;

	i = -1;
	while (++i < nb_line  && !(cpt = 0))
	{
		array->size.y = i;
		if (!(tab_values = ft_tab_strsplit(tab[i], ' ', array)))
			return (ft_free_array(array));
		cpt = ft_strlen((char *)tab_values);
		array->tab[i] = (int *)ft_memalloc(sizeof(int) * (cpt + 1));
		i2 = -1;
		while (tab_values[++i2])
			array->tab[i][i2] = ft_atoi(tab_values[i2]);
		while (--i2)
			ft_memdel((void **)&tab_values[i2]);
		ft_memdel((void **)tab_values);
	}
	return (array);
}

char	**ft_tab_strsplit(char *tab, char c, t_array *a)
{
	char			**tab_values;
	static	int 	len = 0;
	int				len2;

	if (len == 0)
	{
		tab_values = ft_strsplit(tab, c);
		len = ft_strlen((char *)tab_values);
		a->size.x = len;
	}
	else
	{
		tab_values = ft_strsplit(tab, c);
		if (len != (len2 = ft_strlen((char *)tab_values)))
		{
			while (--len2)
				ft_memdel((void **)&tab_values[len2]);
			ft_memdel((void **)tab_values);
		}
	}
	return (tab_values);
}
