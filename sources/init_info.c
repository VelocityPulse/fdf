/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:57:11 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/03 22:20:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_info		*ft_init_info(t_mlx *mlx, t_array *a)
{
	t_info		*info;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	info->mlx = mlx;
	info->array = a;
	info->key = 0;
	info->rad = ft_make_vector(0, 0, 0);
	info->pos = ft_make_pt(400, 350);
	info->scale = ft_make_pt3d(20, 20, 4);
	return (info);
}
