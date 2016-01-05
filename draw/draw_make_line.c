/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:03:45 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/05 14:07:43 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_line	ft_draw_make_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.start.x = x1;
	line.start.y = y1;
	line.end.x = x2;
	line.end.y = y2;
	line.dx = x2 - x1;
	line.dy = y2 - y1;
	return (line);
}
