/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:03:46 by                   #+#    #+#             */
/*   Updated: 2016/01/04 17:30:06 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DRAW_H
# define _DRAW_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"

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

void	ft_new_image(t_mlx *mlx);
void	ft_draw_pixel(t_mlx *mlx, int color, t_pt pt);

#endif
