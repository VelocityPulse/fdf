/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:14:56 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:14:58 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_reset_image(t_mlx *mlx, int color)
{
	int		octet;
	int		position;
	char	*img;

	img = mlx->mlx_img->data;
	octet = mlx->mlx_img->bpp / 8;
	position = 0;
	while (position < mlx->mlx_img->max_size)
	{
		ft_memcpy(img + position, &color, octet);
		position += octet;
	}
}
