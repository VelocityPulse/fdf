/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_array_layout.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 15:31:15 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/27 12:12:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	*ft_array_layout(t_pt3d *pts, int size, t_matrix t)
{
	int		i;
	t_pt	*new_pts;

	i = -1;
	new_pts = (t_pt *)malloc(sizeof(t_pt) * (size + 1));
	while (++i <= size)
		new_pts[i] = ft_multiply_matrix(pts[i], t);
	ft_memdel((void **)&pts);
	return (new_pts);
}
