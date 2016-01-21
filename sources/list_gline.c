/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_gline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:27:31 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/13 14:24:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_gline		*ft_add_line(t_gline *begin, char *line)
{
	t_gline		*list;
	if (!begin)
	{
		begin = ft_add_gline();
		begin->line = line;
		return (begin);
	}
	list = begin;
	while (list->next)
		list = list->next;
	list->next = ft_add_gline();
	list = list->next;
	list->line = line;
	return (begin);
}

t_gline		*ft_add_gline(void)
{
	t_gline		*list;

	list = (t_gline *)malloc(sizeof(t_gline));
	list->next = NULL;
	list->line = NULL;
	return (list);
}

char		**ft_export_gline(t_gline *begin)
{
	t_gline		*list;
	char		**tab;
	int			i;
	int			nbr_line;

	i = 0;
	nbr_line = ft_gline_cpt(list);
	tab = (char **)ft_memalloc(sizeof(char *) * nbr_line);
	while (i <= nbr_line)
	{
		tab[i++] = list->line;
		list = list->next;
	}
	return (tab);
}

void		*ft_free_gline(t_gline *begin)
{
	t_gline		*temp;

	if (!begin)
		return (NULL);
	while (begin)
	{
		temp = begin->next;
		ft_memdel((void **)&begin->line);
		ft_memdel((void **)&begin);
		begin = temp;
	}
	return (begin);
}

int			ft_gline_cpt(t_gline *begin)
{
	int			i;
	t_gline		*list;

	i = 0;
	if (!begin)
		return (0);
	list = begin;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}