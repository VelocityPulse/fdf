/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:40:00 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/06 14:06:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main()
{
	t_mlx *mlx;

	mlx = NULL;
	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (0);
	ft_mlx_init(550, 600, mlx, "fdf");
	ft_draw_line(ft_draw_make_line(300, 200, 550, 200), mlx, (int)0xffffff);
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->mlx_img->p_img, 0, 0);
	mlx_loop(mlx->p_mlx);
}
