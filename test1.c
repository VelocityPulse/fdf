/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 18:50:41 by                   #+#    #+#             */
/*   Updated: 2015/12/25 19:34:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <unistd.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		high;
	int		lenght;
}				t_env;

int		*ft_color_w(int code, t_env *e)
{
	int		x;
	int		y;

	ft_putnbr(code);
	ft_putchar('\n');
	y = 0;
	if (code == 12) // Q
		code = (int)0xff0000;
	else if (code == 13) // W
		code = (int)0x00ff00; 
	else if (code == 14) // E
		code = (int)0x0000ff;
	else
		code = (int)0xffffff;
	while (y < e->high)
	{
		x = 0;
		while (x < e->lenght)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, code);
			x++;
		}
		y++;
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	ft_color_w(keycode, e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.high = 500;
	e.lenght = 600;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.lenght, e.high, "test1");
	mlx_key_hook(e.win, key_hook, &e);
//	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	sleep(5);
	return (0);
}
