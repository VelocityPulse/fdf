/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:14:05 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 11:56:50 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_exit_fdf(t_info *info)
{
	int		i;

	i = 0;
	while (i <= info->array->max_size.y)
		ft_memdel((void **)&info->array->tab[i++]);
	ft_fdf_free_pt3d(info->array);
	ft_fdf_free_pt(info->array);
	ft_memdel((void **)&info->array);
	ft_clear_mlx(info->mlx);
	ft_memdel((void **)&info);
	exit(0);
}
