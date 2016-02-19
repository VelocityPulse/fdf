/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_perimeter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:13:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:13:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_perimeter(t_pt *l, int size, t_mlx *mlx, int color)
{
	int		i;
	t_line	line;

	i = 0;
	if (size < 2)
	{
		line = ft_make_line(l[i].x, l[i].y, l[i + 1].x, l[i + 1].y);
		ft_draw_line(line, mlx, color);
	}
	else
	{
		while (i < size)
		{
			line = ft_make_line(l[i].x, l[i].y, l[i + 1].x, l[i + 1].y);
			ft_draw_line(line, mlx, color);
			i++;
		}
		line = ft_make_line(l[i].x, l[i].y, l[0].x, l[0].y);
		ft_draw_line(line, mlx, color);
	}
}
