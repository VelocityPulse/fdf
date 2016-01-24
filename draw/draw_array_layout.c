/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array_layout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:31:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/24 18:29:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	*ft_array_layout(t_pt *pts, int size, t_matrix t)
{
	int		i;
	t_pt	*new_pts;

	i = 1;
	new_pts = (t_pt *)malloc(sizeof(t_pt) * size);
	while (++i <= size)
		new_pts[i] = ft_multiply_matrix(pts[i], t);
	return (new_pts);
}
