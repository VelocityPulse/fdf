/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:01 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/12 20:21:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_info		*ft_init_info(t_mlx *mlx, t_array *a)
{
	t_info		*info;
	float		graphic_size;

	info = (t_info *)ft_memalloc(sizeof(t_info));
	info->mlx = mlx;
	info->array = a;
	info->key = -1;
	graphic_size = (float)mlx->width / (float)(a->max_size.x * 2);
	info->scale = ft_make_pt3df(graphic_size, graphic_size, 4);
	info->rad = ft_make_vector(0, 0, 0);
	info->pos = ft_make_pt(mlx->width / 2, mlx->height / 2);
	return (info);
}
