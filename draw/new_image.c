/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:00:58 by                   #+#    #+#             */
/*   Updated: 2016/01/06 13:40:21 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

void	ft_new_image(t_mlx *mlx)
{
	t_img	*img;
	void	*d;

	if (!(img = (t_img *)ft_memalloc(sizeof(t_img))))
		return ;
	img->endian = 0;
	img->width = mlx->width;
	img->p_img = mlx_new_image(mlx->p_mlx, mlx->width, mlx->height);
	if (!img->p_img)
		return ;
	d = mlx_get_data_addr(img->p_img, &img->bpp, &img->width, &img->endian);
	img->data = d;
	mlx->mlx_img = img;
	mlx->mlx_img->max_size = (img->bpp / 8) * mlx->width * mlx->height;
}
