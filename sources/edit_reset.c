/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:33:51 by                   #+#    #+#             */
/*   Updated: 2016/02/05 17:48:12 by                  ###   ########.fr       */
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
