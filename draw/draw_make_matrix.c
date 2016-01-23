/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 23:00:18 by                   #+#    #+#             */
/*   Updated: 2016/01/23 14:56:16 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_matrix	ft_rotate_matrix_x(t_matrix m, float rot, t_pt3d scale)
{
	m.x = ft_add_vector(m.x, scale.x, 0.0f, 0.0f);
	m.y = ft_add_vector(m.y, 0.0f, cosf(rot) * scale.y, -sinf(rot) * scale.z);
	m.z = ft_add_vector(m.z, 0.0f, sinf(rot) * scale.y, cosf(rot) * scale.z);
	return (m);
}

t_matrix	ft_rotate_matrix_y(t_matrix m, float rot, t_pt3d scale)
{
	m.x = ft_add_vector(m.x, cosf(rot) * scale.y, 0.0f, sinf(rot) * scale.z);
	m.y = ft_add_vector(m.y, 0.0f, scale.y, 0.0f);
	m.z = ft_add_vector(m.z, -sinf(rot) * scale.x, 0.0f, cosf(rot) * scale.z);
	return (m);
}

t_matrix	ft_rotate_matrix_z(t_matrix m, float rot, t_pt3d scale)
{
	m.x = ft_add_vector(m.x, cosf(rot) * scale.x, -sinf(rot) * scale.y, 0.0f);
	m.y = ft_add_vector(m.y, sinf(rot) * scale.x, sinf(rot) * scale.y, 0.0f);
	m.z = ft_add_vector(m.z, 0.0f, 0.0f, scale.z);
	return (m);
}
