/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    pt3d_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 18:37:05 by                   #+#    #+#             */
/*   Updated: 2016/01/25 15:42:00 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/header.h"

t_pt3d		**ft_pt3d_alloc(t_pt size)
{
	t_pt3d		**pt;
	int			i;

	i = 0;
	pt = (t_pt3d **)malloc(sizeof(t_pt3d *) * (size.y + 1));
	while (i <= size.y)
	{
		pt[i] = (t_pt3d *)malloc(sizeof(t_pt3d) * (size.x + 1));
		i++;
	}
	pt[i] = NULL;
	return (pt);
}

t_pt3d		**ft_free_pt3d(t_pt3d **tab_pts, int size)
{
	if (!tab_pts)
		return (NULL);
	size++;
	while (--size)
		ft_memdel((void **)&tab_pts[size]);
	ft_memdel((void **)tab_pts);
	return (tab_pts);
}

t_pt		**ft_free_pt(t_pt **tab_pts, int size)
{
	if (!tab_pts)
		return (NULL);
	size++;
	while (--size)
		ft_memdel((void **)&tab_pts[size]);
	ft_memdel((void **)tab_pts);
	return (tab_pts);

}
