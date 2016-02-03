/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_add_pt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:47:21 by                   #+#    #+#             */
/*   Updated: 2016/02/03 22:50:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_pt	ft_add_pt(t_pt pt1, t_pt pt2)
{
	t_pt pt3;

	pt3.x = pt1.x + pt2.x;
	pt3.y = pt1.y + pt2.y;
	return (pt3);
}
