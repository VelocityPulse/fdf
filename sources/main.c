/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:26:58 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/21 12:50:39 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	int			fd;
	t_array		*array;

	array = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (0);
		if (!(array = ft_get_array(fd, array)))
			return (0);
		ft_mlx_init(700, 600, mlx, "fdf");
		// appel de fdf !!!!
	}
	return (0);
}
