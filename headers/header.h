/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:55:43 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/02 15:05:32 by cchameyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HEADER_H
# define _HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "draw.h"

# include "debug.h"

typedef struct	s_array
{
		int		**tab;
	t_pt3d	**tab_pts;
	t_pt	**layout_pts;
	t_pt	size;
}				t_array;

typedef struct	s_gline
{
	struct s_gline	*next;
	char			*line;
}				t_gline;

typedef struct	s_info
{
	t_array		*array;
	t_mlx		*mlx;
	int			key;
	t_vector	rad;
}				t_info;

int				ft_fdf(t_info *info);
int				ft_key_hook(int keycode, t_info *info);

t_gline			*ft_add_line(t_gline *begin, char *line);
t_gline			*ft_add_gline(void);
void			*ft_free_gline(t_gline *begin);
int				ft_gline_cpt(t_gline *begin);
char			**ft_export_gline(t_gline *begin);

t_array			*ft_get_array(int fd, t_array *array);
int				ft_check_tab(char **tab, const int nbr_line);
void			*ft_free_tab(char **tab, const int nbr_line);

t_array			*ft_convert_to_array(char **tab, const int nb_line, t_array *a);
char			**ft_tab_strsplit(char *tab, char c, t_array *array);

t_array			*ft_convert_array_to_pts(t_array *a);

t_array			*ft_array_alloc(const int nbr_line);
t_array			*ft_free_array(t_array *array);

t_pt3d			**ft_pt3d_alloc(t_pt size);
t_pt3d			**ft_free_pt3d(t_pt3d **tab_pts, int size);
t_pt			**ft_free_pt(t_pt **tab_pts, int size);

#endif
