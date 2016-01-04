/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:30:22 by                   #+#    #+#             */
/*   Updated: 2016/01/04 17:34:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	int		position;
	int		octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	if (ft_memcmp(mlx->mlx_img->data + position, &color, (unsigned)octet))
		ft_memcpy(mlx->mlx_img->data + position, &color, (unsigned)octet);
}
