/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:35:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/27 17:05:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt3d		**ft_add_scale(t_pt3d **tab, t_pt size, t_pt3d scale)
{
	int		x;
	int		y;

	y = 0;
	while (y <= size.y)
	{
		x = 0;
		while (x <= size.x)
		{
			tab[y][x].x *= scale.x;
			tab[y][x].y *= scale.y;
			tab[y][x].z *= scale.z;
			x++;
		}
		y++;
	}
	return (tab);
}

