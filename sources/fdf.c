/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/02/05 17:17:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_apply_layout(t_array *a, t_matrix m)
{
	int		y;

	y = 0;
	while (y <= a->max_size.y)
	{
		ft_array_layout(a->tab_pts[y], a->size_x[y], a->layout_pts[y], m);
		y++;
	}
}

int		ft_fdf(t_info *info)
{
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
	a->layout_pts = ft_fdf_pt_alloc(a);
	ft_apply_layout(a, rot.m);
	ft_fdf_add_pos(a, rot.m.pos);
	ft_fdf_draw(a, mlx);
	ft_flush_image(mlx);
	return (0);
}
