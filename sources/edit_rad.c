/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:01:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/08 12:04:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_rad(t_info *info)
{
	float	increment;

	increment = (3.1415f / 24);
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
** 126	= fleche haut
** 125	= fleche bas
** 124	= fleche droite
** 123	= fleche gauche
**
** 30	= crochet droit
** 33	= crochet gauche
*/
