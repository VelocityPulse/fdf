/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:30:22 by                   #+#    #+#             */
/*   Updated: 2016/02/04 14:44:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt)
{
	long int	position;
	long int	octet;

	octet = mlx->mlx_img->bpp / 8;
	position = (pt.y * mlx->mlx_img->width) + (pt.x * octet);
	if (pt.y > mlx->height || pt.x > mlx->width || position < 0)
	{
		ft_putstr("yolo\n");
		return ;
	}
	if (ft_memcmp(mlx->mlx_img->data + position, &color, (unsigned)octet) != 0)
			ft_memcpy(mlx->mlx_img->data + position, &color, (unsigned)octet);
}
