/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:21:06 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/21 12:15:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_array		*ft_get_array(int fd, t_array *array)
{
	t_gline		*list_line;
	int			state;
	int			nbr_line;
	char		*line;
	char		**tab;

	state = 1;
	nbr_line = 0;
	line = NULL;
	while (state == 1)
	{
		nbr_line++;
		state = get_next_line(fd, &line);
		list_line = ft_add_line(list_line, line);
	}
	tab = ft_export_gline(list_line);
	list_line = ft_free_gline(list_line);
	if (ft_check_tab(tab, nbr_line) == 1)
		array = ft_convert_to_array(tab, nbr_line);
	if (ft_check_array(array, nbr_line) == 0)
		ft_free_array(array);
	ft_free_tab(tab, nbr_line);
	return (array);
}

int			ft_check_tab(char **tab, const int nbr_line)
{
	int		line;
	int		i;

	while (line <= nbr_line)
	{
		i = 0;
		while (tab[line][i])
		{
			if (!(tab[line][i] >= '0' && tab[line][i] <= '9') &&
					tab[line][i] != ' ')
				return (0);
			i++;
		}
		line++;
	}
	return (1);
}

t_array		*ft_free_array(t_array *array)
{
	int		i;

	i = 0;
	if (!array)
		return (NULL);
	while (i <= array->size.y)
		ft_memdel((void **)&array->tab[i]);
	ft_memdel((void **)&array);
	return (array);
}

void		*ft_free_tab(char **tab, const int nbr_line)
{
	int		i;

	i = 0;
	while (i <= nbr_line)
		ft_memdel((void **)&tab[i++]);
	ft_memdel((void **)tab);
	return (NULL);
}