/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/01/27 12:33:24 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		ft_fdf(t_info *info)
{
	int				x;
	int				y;
	static float	rad = 0;
	float			increment;
	t_matrix		m;
	t_mlx			*mlx;
	t_array			*a;

	increment = (3.1415f / 12);
	mlx = info->mlx;
	a = info->array;

	y = 0;
	while (y <= a->size.y)
	{
		x = 0;
		while (x <= a->size.x)
			printf("%d ", a->tab_pts[y][x++].z);
		printf("\n");
		y++;
	}

	PAUSE
	m = ft_init_matrix(ft_make_pt(400, 200));
//	m = ft_rotate_matrix_y(m, 0);
//	m = ft_rotate_matrix_y(m, 0);
	m = ft_rotate_matrix_x(m, rad);
	m = ft_add_scale(m, ft_make_pt3d(10, 10, 2));

	a->layout_pts = (t_pt **)malloc(sizeof(t_pt *) * (a->size.y + 1));

	y = 0;
	while (y <= a->size.y)
	{
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
	rad += increment;
	a->layout_pts = ft_free_pt(a->layout_pts, a->size.y);
	ft_reset_image(mlx, 0x000000);
	ft_flush_image(mlx);
	return (0);
}
