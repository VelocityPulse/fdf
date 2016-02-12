/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/12 19:18:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_reset(t_info *info)
{
	int		graphic_size;
	if (info->key == 49)
	{
		info->array = ft_convert_array_to_pts(info->array);
		graphic_size = info->mlx->width / (info->array->max_size.x * 2);
		info->scale = ft_make_pt3df(graphic_size, graphic_size, 4);
		info->rad = ft_make_vector(0, 0, 0);
		info->pos = ft_make_pt(info->mlx->width / 2, info->mlx->height / 2);
		ft_fdf_add_scale(info->array, info->scale);
	}
}

/*
** 49 = space
*/
