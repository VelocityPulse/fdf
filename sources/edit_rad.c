/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:50:33 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 14:54:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_rad(t_info *info)
{
	float	increment;

	increment = (M_PI / 24);
	if (info->key == 126)
		info->rad.x -= increment;
	else if (info->key == 125)
		info->rad.x += increment;
	else if (info->key == 124)
		info->rad.y += increment;
	else if (info->key == 123)
		info->rad.y -= increment;
	else if (info->key == 33)
		info->rad.z += increment;
	else if (info->key == 30)
		info->rad.z -= increment;
	else
		return ;
}

/*
** 126	= arrow top
** 125	= arrow bot
** 124	= arrow right
** 123	= arrow left
** 30	= hook right
** 33	= hook left
*/
