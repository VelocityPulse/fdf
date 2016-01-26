/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix_multiply_vector.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:17:10 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/26 15:18:57 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_vector	ft_matrix_multiply_vector(t_vector v, float x, float y, float z)
{
	if (x)
		v.x *= x;
	if (y)
		v.y *= y;
	if (z)
		v.z *= z;
	return (v);
}
