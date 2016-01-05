/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:38:40 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/05 13:43:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_init_mlx(int height, int width, t_mlx *mlx, char *name)
{
	mlx->width = width;
	mlx->height = height;
	mlx->p_mlx = mlx_init();
	mlx->p_win = mlx_new_window(mlx->p_mlx, mlx->width, mlx->height, name);
	ft_new_image(mlx);
}
