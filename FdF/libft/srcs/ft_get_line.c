/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 10:58:52 by sschafer          #+#    #+#             */
/*   Updated: 2017/08/14 10:08:44 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_createline(char *buff, char **line, char *endl)
{
	int			len_buff;
	int			len_line;
	char		*str;
	char		*temp;

	len_buff = ft_strlen(buff);
	len_line = ft_strlen(*line);
	temp = *line;
	str = (len_buff > 0 && len_line == 0) ? buff : *line;
	if (*endl == '\n')
	{
		if (!(*line = ft_strsub(str, 0, endl - str)))
			return (-1);
		buff = ft_strcpy(buff, endl + 1);
	}
	else if (*endl == '\0')
	{
		if (len_buff == 0 && len_line == 0)
			return (0);
		if (!(*line = ft_strsub(str, 0, endl - str)))
			return (-1);
		ft_strclr(buff);
	}
	free(temp);
	return (1);
}

static int		ft_read(const int fd, char *buff, char **line)
{
	int			ret;
	int			count;
	char		*temp;

	count = ft_strlen(buff);
	if (count > 0)
	{
		temp = *line;
		*line = ft_strjoin(*line, buff);
		if (!(*line))
			return (-1);
		free(temp);
	}
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	temp = *line;
	*line = ft_strjoin(*line, buff);
	if (!(*line))
		return (-1);
	free(temp);
	ft_strclr(buff);
	return (ret);
}

int				ft_get_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	char		*endl;
	int			ret;

	if (fd < 0 || !line || !(*line = ft_strnew(0)))
		return (-1);
	endl = ft_strchr(buff, '\n');
	while (!endl)
	{
		ret = ft_read(fd, buff, line);
		if (ret == -1)
			return (-1);
		if (ret == 0)
		{
			endl = ft_strchr(*line, '\0');
			if (endl)
				break ;
		}
		endl = ft_strchr(*line, '\n');
	}
	return (ft_createline(buff, line, endl));
}
