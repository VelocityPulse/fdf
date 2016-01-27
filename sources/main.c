/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:26:58 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/27 15:31:34 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

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
//		array = ft_convert_array_to_pts(array);
		info = (t_info *)malloc(sizeof(t_info));
		info->mlx = mlx;
		info->array = array;

		mlx_loop_hook(mlx->p_mlx, &ft_fdf, info);
		mlx_loop(mlx);
	}
	return (0);
}
