/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_losange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:06:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/22 23:54:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_losange(t_area l, t_mlx *mlx, int color)
{
	ft_draw_line(ft_make_line(l.a.x, l.a.y, l.b.x, l.b.y), mlx, color);
	ft_draw_line(ft_make_line(l.b.x, l.b.y, l.c.x, l.c.y), mlx, color);
	ft_draw_line(ft_make_line(l.c.x, l.c.y, l.d.x, l.d.y), mlx, color);
	ft_draw_line(ft_make_line(l.d.x, l.d.y, l.a.x, l.a.y), mlx, color);
}
