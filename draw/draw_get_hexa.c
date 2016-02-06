/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 16:12:09 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/06 16:58:46 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

#include "../headers/debug.h"

int		ft_get_hexa(t_rgb rgb)
{
	int		hexa;

	hexa = 0;
	hexa += rgb.r * 0x010000;
	hexa += rgb.g * 0x000100;
	hexa += rgb.b * 0x000001;
	return (hexa);
}
