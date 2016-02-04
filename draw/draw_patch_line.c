/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_patch_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:33:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/04 14:45:37 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

static t_line	ft_patch_line_height(t_line line, t_mlx *mlx)
{
	if (line.start.x < 0)
		line.start.x = 0;
	if (line.start.x > mlx->width)
		line.start.x = mlx->width;
	if (line.end.x < 0)
		line.end.x = 0;
	if (line.end.x > mlx->width)
		line.end.x = mlx->width;
	return (line);
}

static t_line	ft_patch_line_width(t_line line, t_mlx *mlx)
{
	if (line.start.y < 0)
		line.start.y = 0;
	if (line.start.y > mlx->height)
		line.start.y = mlx->height;
	if (line.end.y < 0)
		line.end.y = 0;
	if (line.end.y > mlx->height)
		line.end.y = mlx->height;
	return (line);
}

t_line			ft_patch_line(t_line l, t_mlx *mlx)
{
	l = ft_patch_line_height(l, mlx);
	l = ft_patch_line_width(l, mlx);
	l = ft_make_line(l.start.x, l.start.y, l.end.x, l.end.y);
	return (l);
}
