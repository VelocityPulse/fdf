/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:53:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/13 16:12:40 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/headers.h"

t_array		*ft_convert_to_array(char **tab, int nbr_line)
{
	char	**tab_values;
	int 	i;
	int		i2

	i = 0;
	while (i <= nbr_line)
	{
		tab_values = ft_strsplit(tab[i], ' ');
		i2 = 0;
		while (tab_values[i2])
		{
			
		}
	}
}
