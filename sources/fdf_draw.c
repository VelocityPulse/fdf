/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:00:10 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static t_dual_color		ft_fdf_define_gradient(t_array *a, int z1, int z2)
{
	t_dual_color	base;
	t_dual_color	c;

	base.c1 = ft_get_rgb(COLOR_MIN);
	base.c2 = ft_get_rgb(COLOR_MAX);
	z1 += a->min_z;
	z2 += a->min_z;
	c.c1 = ft_find_color_gradient(base, a->theoric_z, z1);
	c.c2 = ft_find_color_gradient(base, a->theoric_z, z2);
	return (c);
}

static void				ft_fdf_draw_color_line(t_fdf_draw f)
{
	t_dual_color	c;
	t_array			*a;
	t_pt			p;
	t_pt			pp;

	a = f.a;
	p = f.p;
	pp = f.pp;
	c = ft_fdf_define_gradient(a, a->tab[p.y][p.x], a->tab[pp.y][pp.x]);
	ft_draw_color_line(f.l, f.mlx, ft_get_hexa(c.c1), ft_get_hexa(c.c2));
}

static void				ft_fdf_draw_horizontal(t_array *a, t_mlx *mlx)
{
	int			x;
	int			y;
	int			o;
	t_pt		**p;
	t_fdf_draw	f;

	p = a->layout_pts;
	y = 0;
	f.a = a;
	f.mlx = mlx;
	while (y <= a->max_size.y)
	{
		x = 0;
		while (x < a->size_x[y])
		{
			o = x + 1;
			f.l = ft_make_line(p[y][x].x, p[y][x].y, p[y][o].x, p[y][o].y);
			f.p = ft_make_pt(x, y);
			f.pp = ft_make_pt(o, y);
			ft_fdf_draw_color_line(f);
			x++;
		}
		y++;
	}
}

static void				ft_fdf_draw_vertical(t_array *a, t_mlx *mlx)
{
	int			x;
	int			y;
	int			o;
	t_pt		**p;
	t_fdf_draw	f;

	p = a->layout_pts;
	f.a = a;
	f.mlx = mlx;
	x = -1;
	while (++x <= a->max_size.x)
	{
		y = -1;
		while (++y < a->max_size.y)
		{
			if (x <= a->size_x[y] && x <= a->size_x[y + 1])
			{
				o = y + 1;
				f.l = ft_make_line(p[y][x].x, p[y][x].y, p[o][x].x, p[o][x].y);
				f.p = ft_make_pt(x, y);
				f.pp = ft_make_pt(x, o);
				ft_fdf_draw_color_line(f);
			}
		}
	}
}

void					ft_fdf_draw(t_array *a, t_mlx *mlx)
{
	ft_fdf_draw_horizontal(a, mlx);
	ft_fdf_draw_vertical(a, mlx);
}
