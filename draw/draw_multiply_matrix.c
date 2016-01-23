/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multiply_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:54:40 by                   #+#    #+#             */
/*   Updated: 2016/01/23 12:13:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	draw_multiply_matrix(t_pt pt, t_matrix t)
{
	t_pt	new_pt;

	new_pt.x = (t.x.x * pt.x) + (t.x.y * pt.y) + t.x.z + t.pos.x;
	new_pt.y = (t.y.x * pt.x) + (t.y.y * pt.y) + t.y.z + t.pos.y;
	return (new_pt);
}
