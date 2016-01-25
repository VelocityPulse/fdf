/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/01/25 16:57:56 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf(t_array *a, t_mlx *mlx)
{
	t_pt		*pt;
	int			i;
	t_matrix	m;

	i = 0;
	a = ft_convert_array_to_pts(a);
	pt = (t_pt *)malloc(sizeof(t_pt) * (a->size.x + 1));
	while (i <= a->size.x)
	{
		pt[i].x = a->tab_pts[0][i].x;
		pt[i].y = a->tab_pts[0][i].y;
		i++;
	}
	a->layout_pts = (t_pt **)malloc(sizeof(t_pt *));
	a->layout_pts[0] = pt;

	m = ft_init_matrix(ft_make_pt(200, 200));
	m = ft_rotate_matrix_z(m, 0, ft_make_pt3d(10, 10, 10));
	pt = ft_array_layout(a->layout_pts[0], a->size.x, m);
	printf("x%d, y%d / x%d, y%d\n", pt[0].x, pt[0].y, pt[1].x, pt[1].y);
	ft_draw_perimeter(pt, a->size.x, mlx, 0xffffff);
	ft_flush_image(mlx);
	mlx_loop(mlx->p_mlx);
}
