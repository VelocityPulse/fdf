/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isocele.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 22:33:59 by                   #+#    #+#             */
/*   Updated: 2016/01/10 00:31:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

#include <stdio.h>

void	ft_draw_isocele(t_area area, int mediane, t_mlx *mlx, int color)
{
	t_pt	o;
	int		ab;

	ft_draw_line(ft_draw_make_line(area.start.x, area.start.y, area.end.x, area.end.y),
	mlx, color);
	o.x = (area.start.x + area.end.x) / 2;
	o.y = (area.start.y + area.end.y) / 2;
	ab = (area.end.x - area.start.x) + (area.end.y - area.start.y);

	ft_draw_line(ft_draw_make_line(o.x, o.y, o.x, o.y), mlx, (int)0xffffff);
	printf("o : (x;y) -> (%d;%d)\ndisance AB : %d\n", o.x, o.y, ab);

	mediane = 0;
}
