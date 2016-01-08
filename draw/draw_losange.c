/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/08 17:30:07 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_losange(t_area area, int width, t_mlx *mlx, int color)
{
	t_pt	intersection;
	t_pt	d;
	t_pt	b;
	int		a;

	intersection.x = area.start.x + (area.end.x - area.start.x);
	intersection.y = area.start.y + (area.end.y - area.start.y);
	a = 1 / ((area.end.x - area.start.x) / (area.end.y - area.start.y));
	d.x = intersection.x / a;
}
