/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:41:53 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/02 11:39:51 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "draw_structs.h"
# include "libft.h"
# include "mlx.h"

t_mlx		*ft_mlx_init(int width, int height, t_mlx *mlx, char *name);
void		ft_new_image(t_mlx *mlx);
void		ft_flush_image(t_mlx *x);
void		ft_draw_pixel(t_mlx *mlx, int color, t_pt pt);
void		ft_reset_image(t_mlx *mlx, int color);

t_pt		ft_make_pt(int x, int y);
t_pt3d		ft_make_pt3d(int x, int y, int z);
t_line		ft_make_line(int x1, int y1, int x2, int y2);
t_area		ft_make_area(t_pt a, t_pt b, t_pt c, t_pt d);
t_area		ft_make_losange(t_line line, int mediane);
t_area		ft_make_isocele(t_line line, int mediane);
t_vector	ft_make_vector(float x, float y, float z);

t_matrix	ft_init_matrix(t_pt pos);
t_vector	ft_add_vector(t_vector v, float x, float y, float z);
t_vector	ft_multiply_vector(t_vector v, float x, float y, float z);

t_matrix	ft_rotate_matrix_x(t_matrix m, float rot);
t_matrix	ft_rotate_matrix_y(t_matrix m, float rot);
t_matrix	ft_rotate_matrix_z(t_matrix m, float rot);
t_pt3d		**ft_add_scale(t_pt3d **tab, t_pt size, t_pt3d scale);
t_pt		**ft_add_pos(t_pt **tab, t_pt size, t_pt pos);

t_pt		ft_apply_matrix(t_pt3d pt, t_matrix t);
t_pt		ft_add_pt(t_pt pt1, t_pt pt2);
t_pt		*ft_array_layout(t_pt3d *pts, int size, t_pt *new_pt, t_matrix t);


void		ft_draw_line(t_line line, t_mlx *mlx, int color);
//corriger les prototypes ici
void		ft_draw_horizontal(t_line line, t_mlx *mlx, int variance, int color);
void		ft_draw_vertical(t_line line, t_mlx *mlx, int variance, int color);
void		ft_draw_bresenham(t_line line, t_mlx *mlx, int color, t_pt variance);
void		ft_draw_perimeter(t_pt *list, int size, t_mlx *mlx, int color);

void		ft_draw_rect(t_line line, t_mlx *mlx, int color);
void		ft_draw_losange(t_area l, t_mlx *mlx, int color);
void		ft_draw_isocele(t_area t, t_mlx *mlx, int color);

#endif
