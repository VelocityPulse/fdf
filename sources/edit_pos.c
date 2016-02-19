/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:49:43 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 14:53:10 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_edit_pos(t_info *info, t_matrix_rot *rot)
{
	int		increment;

	increment = 20;
	if (info->key == 13)
		info->pos.y -= increment;
	else if (info->key == 2)
		info->pos.x += increment;
	else if (info->key == 1)
		info->pos.y += increment;
	else if (info->key == 0)
		info->pos.x -= increment;
	rot->m.pos = info->pos;
}

/*
** 13	= W
** 2	= D
** 1	= S
** 0	= A
*/
