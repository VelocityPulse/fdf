/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab3d_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:37:05 by                   #+#    #+#             */
/*   Updated: 2016/01/24 18:46:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_pt3d		**ft_tab3d_alloc(t_pt size)
{
	t_pt3d		**pt;

	pt = (t_pt3d **)malloc(sizeof(t_pt3d *) * size.y);
	while (size.y)
	{
		pt[size.y] = (t_pt3d *)malloc(sizeof(t_pt3d) * size.x);
		size.y--;
	}
	return (pt);
}

t_pt3d		**ft_free_tab3d(t_pt3d **tab_pts, t_pt size)
{
	if (!tab_pts)
		return (NULL);
	size.y++;
	while (--size.y)
		ft_memdel((void **)&tab_pts[size.y]);
	ft_memdel((void **)tab_pts);
	return (tab_pts);
}
