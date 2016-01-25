/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/25 13:21:17 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_to_array(char **tab, const int nb_line, t_array *a)
{
	char		**tab_values;
	int 		i;
	int			i2;
	int			cpt;

	i = -1;
	while (++i <= nb_line  && !(cpt = 0))
	{
		a->size.y = i;
		if (!(tab_values = ft_tab_strsplit(tab[i], ' ', a)))
			return (ft_free_array(a));
		cpt = ft_strlen((char *)tab_values);
		a->tab[i] = (int *)ft_memalloc(sizeof(int) * (cpt + 1));
		i2 = -1;
		while (++i2 < a->size.x)
			a->tab[i][i2] = ft_atoi(tab_values[i2]);
		while (--i2)
			ft_memdel((void **)&tab_values[i2]);
		ft_memdel((void **)tab_values);
	}
	return (a);
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
		printf("tab_values[] :%s\n", tab_values[7]);
		printf("len :%d\n", a->size.x);
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
		int i;
		i = -1;
		while (tab_values[++i])
			printf("tab_values[%d] :%d\n", i, (int)tab_values[i]);
		TEST
	}
	return (tab_values);
}
