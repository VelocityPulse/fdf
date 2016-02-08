/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:24 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/08 12:06:26 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_reset(t_info *info)
{
	if (info->key == 49)
	{
		info->scale = ft_make_pt3d(20, 20, 4);
		info->rad = ft_make_vector(0, 0, 0);
		info->pos = ft_make_pt(500, 350);
		info->array = ft_convert_array_to_pts(info->array);
		ft_fdf_add_scale(info->array, info->scale);
	}
}

/*
** 49 = space
*/
