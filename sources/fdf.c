/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/02/05 11:34:14 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_fdf(t_info *info)
{
	int				x;
	int				y;
	float			increment;
	t_matrix_rot	rot;
	t_mlx			*mlx;
	t_array			*a;

	increment = (3.1415f / 48) * 2;
	mlx = info->mlx;
	a = info->array;

	ft_reset_image(mlx, 0x000000);
	ft_edit_rad(info);
	ft_edit_scale(info);
	ft_edit_reset(info);

	rot.mx = ft_rotate_matrix_x(info->rad.x);

	rot.my = ft_rotate_matrix_y(info->rad.y);

	rot.mz = ft_rotate_matrix_z(info->rad.z);

	rot.m = ft_multiply_matrix(ft_multiply_matrix(rot.mx, rot.my), rot.mz);

	
	
	ft_edit_pos(info, &rot);
	a->layout_pts = ft_pt_alloc(a->size);
	y = 0;
	while (y <= a->size.y)
	{
		ft_array_layout(a->tab_pts[y], a->size.x, a->layout_pts[y], rot.m);
		y++;
	}
	a->layout_pts = ft_add_pos(a->layout_pts, a->size, rot.m.pos);

	x = 0;
	y = 0;
	while (y < a->size.y)
	{
		x = 0;
		while (x < a->size.x)
		{
			ft_draw_line(
					ft_make_line(	a->layout_pts[y][x].x,
						a->layout_pts[y][x].y,
						a->layout_pts[y][x + 1].x,
						a->layout_pts[y][x + 1].y),
					mlx,
					0xffffff
					);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < a->size.x)
	{
		ft_draw_line(
				ft_make_line(	a->layout_pts[y][x].x,
					a->layout_pts[y][x].y,
					a->layout_pts[y][x + 1].x,
					a->layout_pts[y][x + 1].y),
				mlx,
				0xffffff
				);
		x++;
	}
	x = 0;
	y = 0;
	while (x < a->size.x)
	{
		y = 0;
		while (y < a->size.y)
		{
			ft_draw_line(
					ft_make_line(	a->layout_pts[y][x].x,
						a->layout_pts[y][x].y,
						a->layout_pts[y + 1][x].x,
						a->layout_pts[y + 1][x].y),
					mlx,
					0xffffff
					);
			y++;
		}
		x++;
	}
	y = 0;
	while (y < a->size.y)
	{
		ft_draw_line(
				ft_make_line(	a->layout_pts[y][x].x,
					a->layout_pts[y][x].y,
					a->layout_pts[y + 1][x].x,
					a->layout_pts[y + 1][x].y),
				mlx,
				0xffffff
				);
		y++;
	}

//	a->layout_pts = ft_free_pt(a->layout_pts, a->size.y);
//	a->tab_pts = ft_free_pt3d(a->tab_pts, a->size.y);
	ft_flush_image(mlx);
	return (0);
}
