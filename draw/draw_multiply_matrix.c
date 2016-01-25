/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_multiply_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 11:54:40 by                   #+#    #+#             */
/*   Updated: 2016/01/25 16:48:06 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	ft_multiply_matrix(t_pt pt, t_matrix t)
{
	t_pt	new_pt;

	new_pt.x = (t.x.x * pt.x) + (t.x.y * pt.y) + t.x.z + t.pos.x;
	new_pt.y = (t.y.x * pt.x) + (t.y.y * pt.y) + t.y.z + t.pos.y;
	return (new_pt);
}
