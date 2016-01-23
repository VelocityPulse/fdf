/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_to_pts.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:47:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/23 16:42:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_pt3d	**ft_convert_array_to_pts(t_array *a)
{
	t_pt	pos;

	pos.y = 0;
	a->tab_pts = ft_tab3d_alloc(a->size);
	while (pos.y <= a->size.y)
	{
		pos.x = 0;
		while (pos.x <= a->size.x)
		{
			
		}
	}
}
