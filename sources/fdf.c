/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/02/02 13:08:11 by cchameyr         ###   ########.fr       */
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
	t_matrix		mx;
	t_matrix		my;
	t_matrix		mz;
	t_mlx			*mlx;
	t_array			*a;

	increment = (3.1415f / 48);
	mlx = info->mlx;
	a = info->array;


	a = ft_convert_array_to_pts(a);

	a->tab_pts = ft_add_scale(a->tab_pts, a->size, ft_make_pt3d(20, 20, -4));


	a->layout_pts = (t_pt **)malloc(sizeof(t_pt *) * (a->size.y + 1));
	y = 0;
	while (y <= a->size.y)
		a->layout_pts[y++] = NULL;




	mx = ft_rotate_matrix_x(m, rad);

	my = ft_rotate_matrix_y(m, rad);

//	mz = ft_rotate_matrix_z(m, 0);
	mz.x.x = 0;

//	m = ft_multiply_matrix(ft_multiply_matrix(mx, my), mz);
	m = ft_multiply_matrix(mx, my);
	m.pos = ft_make_pt(300, 300);


	y = 0;
	while (y <= a->size.y)
	{
		YOLO
		a->layout_pts[y] = ft_array_layout(a->tab_pts[y], a->size.x, a->layout_pts[y], m);
		y++;
	}
	YOLO2





	a->layout_pts = ft_add_pos(a->layout_pts, a->size, m.pos);



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
	rad += increment;
	rad += increment;

//	if (rad < 12 || rad > 12)
//		increment = -increment;
	a->layout_pts = ft_free_pt(a->layout_pts, a->size.y);
	a->tab_pts = ft_free_pt3d(a->tab_pts, a->size.y);
	usleep(200000);
	ft_flush_image(mlx);
//	ft_reset_image(mlx, 0x000000);
	return (0);
}
