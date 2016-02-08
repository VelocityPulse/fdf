/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/08 12:06:02 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_info		*ft_init_info(t_mlx *mlx, t_array *a)
{
	t_info		*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	info->mlx = mlx;
	info->array = a;
	info->key = -1;
	info->scale = ft_make_pt3d(20, 20, 4);
	info->rad = ft_make_vector(0, 0, 0);
	info->pos = ft_make_pt(500, 350);
	return (info);
}
