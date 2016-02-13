/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/13 18:14:36 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_reset(t_info *info)
{
	float	graphic_size;
	int		x;

	if (info->key == 49)
	{
		info->array = ft_convert_array_to_pts(info->array);
		x = info->array->max_size.x;
		graphic_size = (float)info->mlx->width / ((float)x * 2);
		info->scale = ft_make_pt3df(graphic_size, graphic_size, 4);
		info->rad = ft_make_vector(0, 0, 0);
		info->pos = ft_make_pt(info->mlx->width / 2, info->mlx->height / 2);
		ft_fdf_add_scale(info->array, info->scale);
	}
}

/*
** 49 = space
*/
