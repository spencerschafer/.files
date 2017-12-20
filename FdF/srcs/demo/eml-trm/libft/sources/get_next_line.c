/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 14:43:17 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/20 10:18:48 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static int		gnl_line(char **line, char **str)
{
	*line = ft_strdup(*str);
	return (2);
}

static int		get_next_copy(char **line, char **str, int size)
{
	char	*cpy;

	cpy = ft_strchr(*str, '\n');
	if (!cpy && !size)
	{
		if (ft_strlen(*str))
		{
			*line = ft_strdup(*str);
			**str = 0;
			return (1);
		}
		else
			return (0);
	}
	if (cpy)
	{
		size = cpy - *str;
		*line = ft_strnew(size);
		ft_strncpy(*line, *str, size);
		*str = ft_strchr(*str, '\n') + 1;
		return (1);
	}
	else if (*str)
		return (gnl_line(line, str));
	return (0);
}

static int		get_next_read(int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*new;

	ft_bzero(buf, BUFF_SIZE + 1);
	while (!(ft_strchr(*str, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) >= 1)
	{
		buf[ret] = '\0';
		new = *str;
		*str = ft_strjoin(new, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str;
	int			ret;

	*line = ft_strnew(1);
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE + 1);
	ret = get_next_read(fd, &str);
	if (ret == -1)
		return (-1);
	else if (ret == 0)
		return (0);
	else
		return (get_next_copy(line, &str, ret));
}
