/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:06:11 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/08 12:06:13 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook(int keycode, t_info *info)
{
	if (keycode == 53)
		ft_exit_fdf(info);
	info->key = keycode;
	ft_fdf(info);
	return (0);
}

int		main(int argc, char **argv)
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
		a = ft_convert_array_to_pts(a);
		mlx = ft_mlx_init(1000, 700, mlx, "fdf");
		info = ft_init_info(mlx, a);
		ft_fdf_add_scale(a, info->scale);
		ft_fdf(info);
		mlx_key_hook(mlx->p_win, key_hook, info);
		mlx_loop(mlx);
	}
	return (0);
}
