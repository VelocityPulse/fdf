/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:09:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:09:47 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

int		ft_get_hexa_rgb(int r, int g, int b)
{
	int		hexa;

	hexa = 0;
	hexa += r * 0x010000;
	hexa += g * 0x000100;
	hexa += b * 0x000001;
	return (hexa);
}

int		ft_get_hexa(t_rgb rgb)
{
	int		hexa;

	hexa = 0;
	hexa += rgb.r * 0x010000;
	hexa += rgb.g * 0x000100;
	hexa += rgb.b * 0x000001;
	return (hexa);
}
