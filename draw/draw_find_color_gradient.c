/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_find_color_gradient.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:10:00 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:10:04 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_rgb	ft_find_color_gradient(t_dual_color c, int n, int p)
{
	t_rgb	d;

	d.r = c.c1.r + (int)(((float)(c.c2.r - c.c1.r) / (float)n) * (float)p);
	d.g = c.c1.g + (int)(((float)(c.c2.g - c.c1.g) / (float)n) * (float)p);
	d.b = c.c1.b + (int)(((float)(c.c2.b - c.c1.b) / (float)n) * (float)p);
	return (d);
}
