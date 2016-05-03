/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 12:18:02 by cchameyr          #+#    #+#             */
/*   Updated: 2016/05/03 12:18:04 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

static void		ft_start_hook(t_mlx *mlx, t_info *info)
{
	mlx_hook(mlx->p_win, KeyPress, KeyPressMask, key_hook, info);
	mlx_loop(mlx);
}

int				key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
		ft_exit_fdf(info);
	info->key = keycode;
	ft_fdf(info);
	return (0);
}

int				main(int argc, char **argv)
{
	t_mlx		*mlx;
	int			fd;
	t_array		*a;
	t_info		*info;

	mlx = NULL;
	a = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		if (!(a = ft_get_array(fd, a)))
		{
			close(fd);
			return (0);
		}
		close(fd);
		mlx = ft_mlx_init(1400, 700, "fdf");
		info = ft_init_info(mlx, &a);
		a = ft_convert_array_to_pts(a);
		ft_fdf_add_scale(a, info->scale);
		ft_fdf(info);
		ft_start_hook(mlx, info);
	}
	return (0);
}

/*
** Resolution for macbook 13' :		1400, 700
** Resolution for macbook retina :	800, 700
** Resolution for mac 42 :			1400, 1000
*/
