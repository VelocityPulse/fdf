/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:40:00 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/22 23:46:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main()
{
	t_mlx *mlx;
	t_line line;

	mlx = NULL;
	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		return (0);
	ft_mlx_init(600, 550, mlx, "fdf");

	ft_draw_line(ft_make_line(599, 0, 200, 350), mlx, (int)0xffffff);
	ft_draw_line(ft_make_line(599, 0, 200, 400), mlx, (int)0x00ff00);
	ft_draw_line(ft_make_line(300, 200, 300, 400), mlx, (int)0xaa00ff);
	ft_draw_line(ft_make_line(0, 0, 580, 480), mlx, (int)0xff0000);
	ft_draw_line(ft_make_line(450, 450, 320, 300), mlx, (int)0xaa00ff);
	ft_draw_rect(ft_make_line(100, 450, 200, 500), mlx, (int)0x0000ff);
	ft_draw_rect(ft_make_line(210, 510, 110, 460), mlx, (int)0x00ff00);

	line = ft_make_line(45, 100, 205, 400);
	ft_draw_losange(ft_make_losange(line, 56), mlx, (int)0xff00ff);
	line = ft_make_line(100, 50, 310, 200);
	ft_draw_isocele(ft_make_isocele(line, -100), mlx, (int)0xff0000);
	mlx_put_image_to_window(mlx->p_mlx, mlx->p_win, mlx->mlx_img->p_img, 0, 0);
	mlx_loop(mlx->p_mlx);
}
