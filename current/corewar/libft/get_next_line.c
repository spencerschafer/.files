/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:27:55 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/08/02 16:45:52 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*realloc_line(char *line, int ctr)
{
	char		*temp;

	temp = ft_strnew(ctr + BUFF_SIZE);
	if (temp == 0)
		return (0);
	ft_strcpy(temp, line);
	free(line);
	return (temp);
}

static char		get_c(const int fd)
{
	static int	ctr;
	static char	*buf;
	static int	index;
	char		c;

	if (!buf)
		buf = ft_strnew(BUFF_SIZE);
	if (index >= ctr)
	{
		ctr = read(fd, buf, BUFF_SIZE);
		if (ctr <= 0)
			return (ctr);
		index = 0;
	}
	c = buf[index];
	index++;
	return (c);
}

int				get_next_line(const int fd, char **line)
{
	size_t		ctr;
	char		temp;

	if (!line || fd < 0 || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	ctr = 0;
	while (1)
	{
		temp = get_c(fd);
		if (temp == '\n' || temp == 0 || temp == -1)
			break ;
		(*line)[ctr] = temp;
		ctr++;
		if (ctr % BUFF_SIZE == 0)
		{
			*line = realloc_line(*line, ctr);
			if (*line == 0)
				return (-1);
		}
	}
	if (temp == 0 && ctr == 0)
		return (0);
	else if (temp == -1)
		return (-1);
	return (1);
}
