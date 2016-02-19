/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_make_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:10:46 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/19 15:10:48 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/draw.h"

t_line	ft_make_line(int x1, int y1, int x2, int y2)
{
	t_line	line;

	line.start = ft_make_pt(x1, y1);
	line.end = ft_make_pt(x2, y2);
	line.dx = x2 - x1;
	line.dy = y2 - y1;
	return (line);
}
