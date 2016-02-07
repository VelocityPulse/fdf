/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:12:09 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/07 13:05:44 by                  ###   ########.fr       */
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
