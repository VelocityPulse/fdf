/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:55:43 by cchameyr          #+#    #+#             */
/*   Updated: 2016/02/05 11:32:34 by cchameyr         ###   ########.fr       */
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

typedef struct	s_gline
{
	struct s_gline	*next;
	char			*line;
}				t_gline;

typedef struct	s_array
{
	int		**tab;
	t_pt3d	**tab_pts;
	t_pt	**layout_pts;
	int		*size_x;
	t_pt	max_size;
}				t_array;

typedef struct	s_info
{
	t_array		*array;
	t_mlx		*mlx;
	int			key;
	t_vector	rad;
	t_pt		pos;
	t_pt3d		scale;
}				t_info;

int				ft_fdf(t_info *info);
void			ft_exit_fdf(t_info *info);
int				ft_key_hook(int keycode, t_info *info);
t_info			*ft_init_info(t_mlx *mlx, t_array *a);

t_gline			*ft_add_line(t_gline *begin, char *line);
t_gline			*ft_add_gline(void);
void			*ft_free_gline(t_gline *begin);
int				ft_gline_cpt(t_gline *begin);
char			**ft_export_gline(t_gline *begin);

t_array			*ft_get_array(int fd, t_array *array);
int				ft_check_tab(char **tab, const int nbr_line);
void			*ft_free_tab(char **tab, const int nbr_line);

t_array			*ft_convert_to_array(char **tab, const int nb_line, t_array *a);

t_array			*ft_convert_array_to_pts(t_array *a);

t_pt3d			**ft_fdf_pt3d_alloc(t_array *a);
t_pt3d			**ft_fdf_free_pt3d(t_array *a);

void			ft_fdf_add_scale(t_array *a, t_pt3d scale);

void			ft_edit_rad(t_info *info);
void			ft_edit_pos(t_info *info, t_matrix_rot *rot);
void			ft_edit_scale(t_info *info);
void			ft_edit_reset(t_info *info);

t_array			*ft_array_alloc(const int nbr_line);
t_array			*ft_free_array(t_array *array);

#endif
