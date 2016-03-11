/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:05:39 by cchameyr          #+#    #+#             */
/*   Updated: 2016/03/11 13:18:21 by cchameyr         ###   ########.fr       */
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

	nbr_line = -1;
	line = NULL;
	list_line = NULL;
	while ((state = get_next_line(fd, &line) > 0))
	{
		nbr_line++;
		list_line = ft_add_line(list_line, line);
	}
	if (state == -1)
		return (ft_free_gline(list_line));
	if (list_line == NULL)
		return (NULL);
	tab = ft_export_gline(list_line);
	if (!ft_check_tab(tab, nbr_line))
		return (ft_free_tab(tab, nbr_line));
	array = ft_convert_to_array(tab, ft_array_alloc(nbr_line));
	ft_free_tab(tab, nbr_line);
	return (array);
}

int			ft_check_tab(char **tab, const int nbr_line)
{
	int			line;
	int			i;
	static int	nb_char = 0;

	line = 0;
	while (line <= nbr_line)
	{
		i = 0;
		nb_char = 0;
		while (tab[line][i])
		{
			if (!(tab[line][i] >= '0' && tab[line][i] <= '9') &&
					tab[line][i] != ' ' && tab[line][i] != '-')
				return (0);
			if (ft_isalnum(tab[line][i]))
				nb_char++;
			i++;
		}
		if (nb_char == 0)
			return (0);
		line++;
	}
	return (1);
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
