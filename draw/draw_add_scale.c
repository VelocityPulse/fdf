/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:35:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/26 12:41:03 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_matrix	ft_add_scale(t_matrix m, t_pt3d scale)
{
	m.x = ft_multiply_vector(m.x, scale.x, scale.y, scale.z);
	m.y = ft_multiply_vector(m.y, scale.x, scale.y, scale.z);
	m.z = ft_multiply_vector(m.z, scale.x, scale.y, scale.z);
	return (m);
}

