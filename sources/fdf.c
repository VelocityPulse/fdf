/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 20:13:53 by                   #+#    #+#             */
/*   Updated: 2016/01/24 21:52:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf(t_array *a, t_mlx *mlx)
{
	t_pt	*pt;
	int		i;

	i = 0;
	a = ft_convert_array_to_pts(a);
	pt = (t_pt *)malloc(sizeof(t_pt) * a->size.x);
	while (i <= a->size.x)
	{
		pt[i].x = a->tab_pts[0][i].x;
		pt[i].y = a->tab_pts[0][i].y;
		i++;
	}
	ft_draw_perimeter(pt, a->size.x, mlx, 0x00ff00);
}
