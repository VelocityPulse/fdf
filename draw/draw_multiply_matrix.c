/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multiply_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:54:40 by                   #+#    #+#             */
/*   Updated: 2016/01/27 17:08:55 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	ft_multiply_matrix(t_pt3d pt, t_matrix t)
{
	t_pt	new_pt;

	new_pt.x = (t.x.x * pt.x) + (t.x.y * pt.y) + (t.x.z * pt.z);
	new_pt.y = (t.y.x * pt.x) + (t.y.y * pt.y) + (t.y.z * pt.z);
	return (new_pt);
}
