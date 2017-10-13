/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:37:19 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:24:13 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

char	*line_epur(char *str, char *line)
{
	int		fd;
	int		ret;
	int		i;

	i = -1;
	ret = 0;
	fd = open(".tmp", O_WRONLY | O_TRUNC);
	while (str[++i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			ret += write(fd, &str[i], 1);
		else if (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t')
			ret += write(fd, " ", 1);
	}
	close(fd);
	fd = open(".tmp", O_RDONLY);
	line = (char *)malloc(sizeof(char) * ret + 1);
	bzero(line, ret + 1);
	read(fd, line, ret);
	close(fd);
	return (line);
}

void	ask_samples(void)
{
	printf(KMAG "Eg of questions:\n" RESET);
	printf(KBLUE "\twhat is the value of C\n" RESET);
	printf(KBLUE "\twhy is C false\n" RESET);
	printf(KBLUE "\tadd fact A is true\n" RESET);
	printf(KBLUE "\tremove fact A\n" RESET);
	printf(KBLUE "\tadd or remove rule A + C => D\n" RESET);
	printf(KBLUE "\tlist rules\n" RESET);
}
