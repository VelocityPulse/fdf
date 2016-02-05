/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 13:30:52 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_convert_to_array(char **tab, t_array *a)
{
	char	**tab_values;
	int		i;
	int		i2;

	i = 0;
	a->max_size.y = ft_memlen((void **)tab) - 1;
	a->size_x = (int *)ft_memalloc(sizeof(int) * (a->max_size.y + 1));
	while (i <= a->max_size.y)
	{
		tab_values = ft_strsplit(tab[i], ' ');
		a->size_x[i] = ft_memlen((void **)tab_values) - 1;
		a->tab[i] = (int *)ft_memalloc(sizeof(int) * (a->size_x[i] + 1));
		i2 = -1;
		while (++i2 <= a->size_x[i])
			a->tab[i][i2] = ft_atoi(tab_values[i2]);
		while (--i2)
			ft_memdel((void **)&tab_values[i2]);
		ft_memdel((void **)tab_values);
		if (a->max_size.x < a->size_x[i])
			a->max_size.x = a->size_x[i];
		i++;
	}
	return (a);
}

/*
** t_array		*ft_convert_to_array(char **tab, const int nb_line, t_array *a)
** {
** 	char		**tab_values;
** 	int 		i;
** 	int			i2;
**
** 	i = 0;
** 	a->max_size.y = 0;
** 	while (i <= nb_line)
** 	{
** 		if (!(tab_values = ft_tab_strsplit(tab[i], ' ', a)))
** 			return (ft_free_array(a));
** 		a->tab[i] = (int *)ft_memalloc(sizeof(int) * (a->max_size.x + 1));
** 		i2 = -1;
** 		while (++i2 <= a->max_size.x && (tab_values))
** 			a->tab[i][i2] = ft_atoi(tab_values[i2]);
** 		while (--i2)
** 			ft_memdel((void **)&tab_values[i2]);
** 		ft_memdel((void **)tab_values);
** 		a->max_size.y = i;
** 		i++;
** 	}
** 	return (a);
** }
*/
