/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_rad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:01:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/02 16:05:20 by cchameyr         ###   ########.fr       */
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
	else
		return ;
}
