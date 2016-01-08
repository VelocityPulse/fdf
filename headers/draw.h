/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:41:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/08 11:54:22 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include "draw_structs.h"
# include "libft.h"
# include "mlx.h"

void	ft_mlx_init(int width, int height, t_mlx *mlx, char *name);
void	ft_new_image(t_mlx *mlx);
void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt);
t_line	ft_draw_make_line(int x1, int y1, int x2, int y2);
void	ft_draw_line(t_line line, t_mlx *mlx, int color);
void	ft_draw_horizontal(t_line line, t_mlx *mlx, int variance, int color);
void	ft_draw_vertical(t_line line, t_mlx *mlx, int variane, int color);
void	ft_draw_bresenham(t_line line, t_mlx *mlx, int color, t_pt variance);

#endif
