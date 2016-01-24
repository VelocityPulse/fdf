/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_reset_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:46:59 by                   #+#    #+#             */
/*   Updated: 2016/01/24 20:23:52 by                  ###   ########.fr       */
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
