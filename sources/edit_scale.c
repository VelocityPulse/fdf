/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:07:16 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/11 15:22:12 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_scale_x(t_info *info)
{
	if (info->key == 12)
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(-1, 0, 0));
	else
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(1, 0, 0));
}

/*
** 12	= Q = moins de largeur
** 14	= E = plus de largeur
*/

static void		ft_scale_y(t_info *info)
{
	if (info->key == 3)
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(0, -1, 0));
	else
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(0, 1, 0));
}

/*
** 3	= D = less de hauteur
** 15	= E = more de hauteur
*/

static void		ft_scale_z(t_info *info)
{
	if (info->key == 5)
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(0, 0, -1));
	else
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(0, 0, 1));
}

/*
** 5	= G = less de profondeur
** 17	= T = more de profondeur
*/

static void		ft_general_scale(t_info *info)
{
	if (info->key == 27 || info->key == 78)
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(-3, -3, -1));
	else
		info->scale = ft_add_pt3df(info->scale, ft_make_pt3df(3, 3, 1));
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
