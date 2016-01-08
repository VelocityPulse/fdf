/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:49:38 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/08 11:56:19 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_STRUCTS_H
# define _DRAW_STRUCTS_H

# include "libft.h"
# include "mlx.h"

typedef struct	s_area
{
	t_pt	start;
	t_pt	end;
}				t_area;

typedef struct	s_line
{
	t_pt	start;
	t_pt	end;
	int		dx;
	int		dy;
}				t_line;

typedef struct	s_img
{
	char	*data;
	void	*p_img;
	int		width;
	int		bpp;
	int		endian;
	int		max_size;
}				t_img;

typedef struct	s_mlx
{
	void	*p_mlx;
	void	*p_win;
	int		height;
	int		width;
	t_img	*mlx_img;
}				t_mlx;

#endif
