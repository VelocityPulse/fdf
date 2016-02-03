/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/03 17:24:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_to_array(char **tab, const int nb_line, t_array *a)
{
	char		**tab_values;
	int 		i;
	int			i2;

	i = 0;
	a->size.y = 0;
	while (i <= nb_line)
	{
		if (!(tab_values = ft_tab_strsplit(tab[i], ' ', a)))
			return (ft_free_array(a));
		a->tab[i] = (int *)ft_memalloc(sizeof(int) * (a->size.x + 1));
		i2 = -1;
		while (++i2 <= a->size.x && (tab_values))
			a->tab[i][i2] = ft_atoi(tab_values[i2]);
		while (--i2)
			ft_memdel((void **)&tab_values[i2]);
		ft_memdel((void **)tab_values);
		a->size.y = i;
		i++;
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
		len = ft_memlen((void **)tab_values);
		len--;
		a->size.x = len;
	}
	else
	{
		tab_values = ft_strsplit(tab, c);
		if ((len + 1) != (len2 = ft_memlen((void **)tab_values)))
		{
			len2--;
			while (len2--)
				ft_memdel((void **)&tab_values[len2]);
			ft_memdel((void **)tab_values);
		}
	}
	return (tab_values);
}
