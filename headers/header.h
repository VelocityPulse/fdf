/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:55:43 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/21 16:00:05 by cchameyr         ###   ########.fr       */
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

typedef struct	s_array
{
	int		**tab;
	t_pt	size;
}				t_array;

typedef struct	s_gline
{
	struct s_gline	*next;
	char			*line;
}				t_gline;

t_gline			*ft_add_line(t_gline *begin, char *line);
t_gline			*ft_add_gline(void);
void			*ft_free_gline(t_gline *begin);
int				ft_gline_cpt(t_gline *begin);
char			**ft_export_gline(t_gline *begin);

t_array			*ft_get_array(int fd, t_array *array);
int				ft_check_tab(char **tab, const int nbr_line);
void			*ft_free_tab(char **tab, const int nbr_line);

t_array			*ft_convert_to_array(char **tab, const int nb_line, t_array *a);
char			**ft_tab_strsplit(char *tab, char c);

t_array			*ft_array_alloc(const int nbr_line);
t_array			*ft_free_array(t_array *array);

#endif
