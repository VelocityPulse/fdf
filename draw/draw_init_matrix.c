/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_init_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:10:16 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:10:17 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_matrix	ft_init_matrix(t_pt pos)
{
	t_matrix	m;

	m.x = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.y = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.z = ft_make_vector(0.0f, 0.0f, 0.0f);
	m.pos = pos;
	return (m);
}
