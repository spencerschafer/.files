/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:18:21 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:23:54 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	read_facts(char *line)
{
	int		i;

	i = 0;
	while (line[++i] != '\0')
	{
		if (ft_strchr(LOGICS, line[i]) == NULL)
			exit(printf(KRED "\tInvalid fact: " KBLUE "%c\n" RESET, line[i]));
		else
			fact_base(ADD, line[i], TRUE);
	}
	if (g_verbose == TRUE)
	{
		printf(KMAG "%s\n" RESET, &line[1]);
		printf(KRED "\tfacts Added\n" RESET);
	}
	return (0);
}

static int	read_query(char *line)
{
	int		i;

	i = 0;
	while (line[++i] != '\0')
	{
		if (ft_strchr(LOGICS, line[i]) == NULL)
			exit(printf(KRED "\tInvalid Query: " KBLUE "%c\n" RESET, line[i]));
	}
	g_query = ft_strdup(&line[1]);
	if (g_verbose == TRUE)
	{
		printf(KMAG "%s\n" RESET, g_query);
		printf(KRED "\tQuery Added\n" RESET);
	}
	return (0);
}

static int	read_rule(char *line)
{
	if (is_valid_rule(line) == FALSE)
		exit(printf(KRED "\tInvalid rule: " KBLUE "%s\n", line));
	rule_base(SETUP, NULL, line);
	return (TRUE);
}

static int	read_line(char *line)
{
	char	*str;

	line = ft_strtrim(line);
	str = NULL;
	str = line_epur(line, str);
	if (ft_strlen(str) > 0 && str[0] == '=')
		read_facts(str);
	else if (ft_strlen(str) > 0 && str[0] == '?')
		read_query(str);
	else if (ft_strlen(str) > 0)
		read_rule(str);
	return (0);
}

int		read_file(int fd)
{
	char	*line;
	char	str[256];

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line != NULL && ft_strlen(line) > 0)
		{
			bzero(str, 256);
			ft_memccpy(str, line, '#', ft_strlen(line));
			if (ft_strlen(str) > 0)
				read_line(&str[0]);
		}
	}
	return (0);
}
