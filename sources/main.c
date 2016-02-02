/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:26:58 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/02 15:07:29 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		key_hook(int keycode, t_info *info)
{
	info->key = keycode;
	ft_fdf(info);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	int			fd;
	t_array		*array;
	t_info		*info;

	mlx = NULL;
	array = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		if (!(array = ft_get_array(fd, array)))
			return (0);

		mlx = ft_mlx_init(700, 600, mlx, "fdf");

		info = (t_info *)malloc(sizeof(t_info));
		info->mlx = mlx;
		info->array = array;
		info->key = 0;
		info->rad = ft_make_vector(0, 0, 0);

		mlx_key_hook(mlx->p_win, key_hook, info);
		mlx_loop(mlx);
	}
	return (0);
}
