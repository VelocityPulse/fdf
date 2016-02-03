/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:26:58 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/03 12:46:42 by cchameyr         ###   ########.fr       */
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
			return (0);

		a = ft_convert_array_to_pts(a);
		a->tab_pts = ft_add_scale(a->tab_pts, a->size, ft_make_pt3d(20, 20, 4));

		mlx = ft_mlx_init(700, 600, mlx, "fdf");

		info = ft_init_info(mlx, a);

		mlx_key_hook(mlx->p_win, key_hook, info);
		mlx_loop(mlx);
	}
	return (0);
}
