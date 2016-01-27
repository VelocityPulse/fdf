/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:09:58 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/27 17:06:14 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_matrix	ft_rotate_matrix_x(t_matrix m, float rot)
{
	m.x = ft_make_vector(1.0f, 0.0f, 0.0f);
	m.y = ft_make_vector(0.0f, cosf(rot), -sinf(rot));
	m.z = ft_make_vector(0.0f, sinf(rot), cosf(rot));
	return (m);
}

t_matrix	ft_rotate_matrix_y(t_matrix m, float rot)
{
	m.x = ft_make_vector(cosf(rot), 0.0f, sinf(rot));
	m.y = ft_make_vector(0.0f, 1.0f, 0.0f);
	m.z = ft_make_vector(-sinf(rot), 0.0f, cosf(rot));
	return (m);
}

t_matrix	ft_rotate_matrix_z(t_matrix m, float rot)
{
	m.x = ft_make_vector(cosf(rot), -sinf(rot), 0.0f);
	m.y = ft_make_vector(sinf(rot), cosf(rot), 0.0f);
	m.z = ft_make_vector(0.0f, 0.0f, 1.0f);
	return (m);
}
