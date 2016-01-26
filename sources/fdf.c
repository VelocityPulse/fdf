/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/01/26 13:23:05 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf(t_array *a, t_mlx *mlx)
{
	int			x;
	int			y;
	t_matrix	m;

	a = ft_convert_array_to_pts(a);

	m = ft_init_matrix(ft_make_pt(400, 200));
	m = ft_rotate_matrix_y(m, (3.1415f / 2));
//	m = ft_rotate_matrix_z(m, (3.1415f / 2));
//	m = ft_rotate_matrix_x(m, (3.1415f / 2));
	m = ft_add_scale(m, ft_make_pt3d(20, 20, 4));


//	m = ft_rotate_matrix_x(m, (3 * 3.1415f) / 2, ft_make_pt3d(10, 10, 2));
//	m = ft_rotate_matrix_y(m, (3.14f / 2), ft_make_pt3d(10, 10, 2));


	y = 0;
	a->layout_pts = (t_pt **)malloc(sizeof(t_pt *) * (a->size.y + 1));
	while (y <= a->size.y)
	{
		x = 0;
		a->layout_pts[y] = (t_pt *)malloc(sizeof(t_pt) * (a->size.x + 1));
		while (x <= a->size.x)
		{
			a->layout_pts[y][x].x = a->tab_pts[y][x].x;
			a->layout_pts[y][x].y = a->tab_pts[y][x].y;
			x++;
		}
		a->layout_pts[y] = ft_array_layout(a->tab_pts[y], a->size.x, m);
		y++;
	}

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
	ft_flush_image(mlx);
	mlx_loop(mlx);
}
