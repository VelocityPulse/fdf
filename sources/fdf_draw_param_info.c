/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_param_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:06:57 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:07:44 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_draw_param_radx(t_mlx *mlx, float rad)
{
	char	*str;
	char	*temp1;
	char	*temp2;

	str = ft_strdup("radian x : ");
	if (rad < 0 && (temp1 = str))
	{
		str = ft_strjoin(temp1, "-");
		ft_memdel((void **)&temp1);
	}
	temp1 = str;
	temp2 = ft_itoa(rad < 0 ? -rad : rad);
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	temp1 = str;
	str = ft_strjoin(str, ".");
	ft_memdel((void **)&temp1);
	temp1 = str;
	temp2 = ft_itoa((int)((rad < 0 ? -rad : rad) * 100000));
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	mlx_string_put(mlx->p_mlx, mlx->p_win, 10, mlx->height - 70, 0xffff, str);
	ft_memdel((void **)&str);
}

static void		ft_draw_param_rady(t_mlx *mlx, float rad)
{
	char	*str;
	char	*temp1;
	char	*temp2;

	str = ft_strdup("radian y : ");
	if (rad < 0 && (temp1 = str))
	{
		str = ft_strjoin(temp1, "-");
		ft_memdel((void **)&temp1);
	}
	temp1 = str;
	temp2 = ft_itoa(rad < 0 ? -rad : rad);
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	temp1 = str;
	str = ft_strjoin(str, ".");
	ft_memdel((void **)&temp1);
	temp1 = str;
	temp2 = ft_itoa((int)((rad < 0 ? -rad : rad) * 100000));
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	mlx_string_put(mlx->p_mlx, mlx->p_win, 10, mlx->height - 50, 0xffff, str);
	ft_memdel((void **)&str);
}

static void		ft_draw_param_radz(t_mlx *mlx, float rad)
{
	char	*str;
	char	*temp1;
	char	*temp2;

	str = ft_strdup("radian z : ");
	if (rad < 0 && (temp1 = str))
	{
		str = ft_strjoin(temp1, "-");
		ft_memdel((void **)&temp1);
	}
	temp1 = str;
	temp2 = ft_itoa(rad < 0 ? -rad : rad);
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	temp1 = str;
	str = ft_strjoin(str, ".");
	ft_memdel((void **)&temp1);
	temp1 = str;
	temp2 = ft_itoa((int)((rad < 0 ? -rad : rad) * 100000));
	str = ft_strjoin(temp1, temp2);
	ft_memdel((void **)&temp1);
	ft_memdel((void **)&temp2);
	mlx_string_put(mlx->p_mlx, mlx->p_win, 10, mlx->height - 30, 0xffff, str);
	ft_memdel((void **)&str);
}

void			ft_fdf_draw_param_info(t_mlx *mlx, t_vector rad)
{
	if (floor(rad.x) == 0 && rad.x < 0)
		rad.x = 0;
	if (floor(rad.y) == 0 && rad.y < 0)
		rad.y = 0;
	if (floor(rad.z) == 0 && rad.z < 0)
		rad.z = 0;
	ft_draw_param_radx(mlx, rad.x);
	ft_draw_param_rady(mlx, rad.y);
	ft_draw_param_radz(mlx, rad.z);
}
