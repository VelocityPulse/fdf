/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:30:22 by                   #+#    #+#             */
/*   Updated: 2016/01/08 12:47:20 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

#include <stdio.h>

void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	int		position;
	int		octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	
	printf("x;y -> %d;%d\n", pt.x, pt.y);

	if (ft_memcmp(mlx->mlx_img->data + position, &color, (unsigned)octet) != 0)
		ft_memcpy(mlx->mlx_img->data + position, &color, (unsigned)octet);
}
