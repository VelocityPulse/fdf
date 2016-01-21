/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchameyr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:48:37 by cchameyr          #+#    #+#             */
/*   Updated: 2016/01/21 19:26:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static char		*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_strncpy(ft_strnew(i), str, i);
	line[i] = 0;
	return (line);
}

static char		*ft_end_chain(char *str)
{
	int		i;
	char	*end_chain;

	i = 0;
	end_chain = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	end_chain = ft_strdup(&str[i + 1]);
	if (i == (int)ft_strlen(str))
		ft_memdel((void **)&end_chain);
	ft_memdel((void **)&str);
	return (end_chain);
}

static int		ft_alloc_gnl(char **save, char **buff)
{
	if (!(*buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!*save)
	{
		if (!(*save = ft_strnew(1)))
			return (-1);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		*buff;
	char		*temp;
	int			ret;

	if (((ret = 42)) && (ft_alloc_gnl(&save, &buff) == -1))
		return (-1);
	while (!(ft_strchr(save, '\n')) && ret > 0)
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		buff[ret] = 0;
		temp = save;
		save = ft_strjoin(save, buff);
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)&buff);
	*line = ft_get_line(save);
	save = ft_end_chain(save);
	if (ret == 0 && !save)
	{
		ft_memdel((void **)&save);
		return (0);
	}
	return (1);
}
