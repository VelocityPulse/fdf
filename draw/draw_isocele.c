/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_isocele.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:06:21 by                   #+#    #+#             */
/*   Updated: 2016/01/12 14:09:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_isocele(t_area t, t_mlx *mlx, int color)
{
	ft_draw_line(ft_draw_make_line(t.a.x, t.a.y, t.b.x, t.b.y), mlx, color);
	ft_draw_line(ft_draw_make_line(t.b.x, t.b.y, t.c.x, t.c.y), mlx, color);
	ft_draw_line(ft_draw_make_line(t.c.x, t.c.y, t.d.x, t.d.y), mlx, color);
}
