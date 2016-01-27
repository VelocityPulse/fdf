/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:11:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/27 17:14:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	**ft_add_pos(t_pt **tab, t_pt size, t_pt pos)
{
	int x;
	int y;

	y = 0;
	while (y <= size.y)
	{
		x = 0;
		while (x <= size.x)
		{
			tab[y][x].x += pos.x;
			tab[y][x].y += pos.y;
			x++;
		}
		y++;
	}
	return (tab);
}
