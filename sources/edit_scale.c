/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:56:52 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 14:58:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_scale_x(t_info *info)
{
	if (info->key == 12)
		info->scale.x /= 1.1f;
	else
		info->scale.x *= 1.1f;
}

/*
** 12	= Q = less x
** 14	= E = more x
*/

static void		ft_scale_y(t_info *info)
{
	if (info->key == 3)
		info->scale.y /= 1.1f;
	else
		info->scale.y *= 1.1f;
}

/*
** 3	= D = less y
** 15	= E = more y
*/

static void		ft_scale_z(t_info *info)
{
	if (info->key == 5)
		info->scale.z /= 1.1f;
	else
		info->scale.z *= 1.1f;
}

/*
** 5	= G = less z
** 17	= T = more z
*/

static void		ft_general_scale(t_info *info)
{
	if (info->key == 27 || info->key == 78)
	{
		info->scale.x /= 1.1f;
		info->scale.y /= 1.1f;
		info->scale.z /= 1.1f;
	}
	else
	{
		info->scale.x *= 1.1f;
		info->scale.y *= 1.1f;
		info->scale.z *= 1.1f;
	}
}

/*
** 24	= "+" for macbook air
** 69	= "+" for numpad
** 27	= "-" for macbook air
** 78	= "-" for numpad
*/

void			ft_edit_scale(t_info *info)
{
	int key;

	key = info->key;
	if (!info->array->tab_pts)
	{
		info->array = ft_convert_array_to_pts(info->array);
		ft_fdf_add_scale(info->array, info->scale);
		return ;
	}
	else if (key == 12 || key == 14)
		ft_scale_x(info);
	else if (key == 15 || key == 3)
		ft_scale_y(info);
	else if (key == 17 || key == 5)
		ft_scale_z(info);
	else if (key == 24 || key == 69 || key == 27 || key == 78)
		ft_general_scale(info);
	else
		return ;
	info->array = ft_convert_array_to_pts(info->array);
	ft_fdf_add_scale(info->array, info->scale);
}
