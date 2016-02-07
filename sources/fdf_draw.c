/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 16:17:28 by                   #+#    #+#             */
/*   Updated: 2016/02/07 16:39:30 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"
/*
static t_dual_color		ft_define_gradient(t_array *a, int z1, int z2)
{
	t_dual_color	base;

	base.c1 = COLOR_MIN;
	base.c2 = COLOR_MAX;
//	c.c1 = ft_find_color_gradient(base, )
}
*/
static void		ft_fdf_draw_horizontal(t_array *a, t_mlx *mlx)
{
	int			x;
	int			xx;
	int			y;
	t_pt		**p;
	t_line		l;

	p = a->layout_pts;
	y = 0;
	while (y <= a->max_size.y)
	{
		x = 0;
		while (x < a->size_x[y])
		{
			xx = x + 1;
			l = ft_make_line(p[y][x].x, p[y][x].y, p[y][xx].x, p[y][xx].y);
			ft_draw_line(l, mlx, 0xffffff);
			x++;
		}
		y++;
	}
}

static void		ft_fdf_draw_vertical(t_array *a, t_mlx *mlx)
{
	int		x;
	int		y;
	int		yy;
	t_pt	**p;
	t_line	l;

	p = a->layout_pts;
	x = 0;
	while (x <= a->max_size.x)
	{
		y = 0;
		while (y < a->max_size.y)
		{
			if (x <= a->size_x[y] && x <= a->size_x[y + 1])
			{
				yy = y + 1;
				l = ft_make_line(p[y][x].x, p[y][x].y, p[yy][x].x, p[yy][x].y);
				ft_draw_line(l, mlx, 0xffffff);
			}
			y++;
		}
		x++;
	}
}

void			ft_fdf_draw(t_array *a, t_mlx *mlx)
{
	ft_fdf_draw_horizontal(a, mlx);
	ft_fdf_draw_vertical(a, mlx);
}
