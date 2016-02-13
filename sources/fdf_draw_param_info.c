/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_param_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 23:57:41 by                   #+#    #+#             */
/*   Updated: 2016/02/13 15:26:42 by cchameyr         ###   ########.fr       */
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
	temp2 = ft_itoa((int)((rad < 0 ? -rad : rad)* 100000));
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

void	ft_fdf_draw_param_info(t_array *a, t_mlx *mlx, t_vector rad)
{

	ft_draw_param_radx(mlx, rad.x);
	ft_draw_param_rady(mlx, rad.y);
	ft_draw_param_radz(mlx, rad.z);
	a = NULL;
	rad.x = 2;
}
