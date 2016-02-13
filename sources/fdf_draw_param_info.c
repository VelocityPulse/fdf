/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_param_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 23:57:41 by                   #+#    #+#             */
/*   Updated: 2016/02/13 12:56:54 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

void	ft_fdf_draw_param_info(t_array *a, t_mlx *mlx, t_vector rad)
{
	void	*m;
	void	*w;
	char	*str;

	m = mlx->p_mlx;
	w = mlx->p_win;
	mlx_string_put(m, w, 10, mlx->height - 90, 0xffff, "radian x :");
	mlx_string_put(m, w, 116, mlx->height - 90, 0xffff, (str = ft_itoa(rad.x)));
	ft_memdel((void **)&str);
	a = NULL;
	rad.x = 2;
}
