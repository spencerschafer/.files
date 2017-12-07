/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:26:29 by sschafer          #+#    #+#             */
/*   Updated: 2017/12/07 13:27:19 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf()
#include "libft.h" //libft functions
#include <fcntl.h>

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		int			x;
		int			y;
		int 		fd;
		int			ret;
		char 		*line;
		char		***str = NULL;

		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("[%s]\n", line);
			str = ft_map(str, line);
			free(line);
		}
		y = 0;
		while (str[y])
		{
			x = 0;
			printf("[");
			while (str[y][x])
				printf("[%s]", str[y][x++]);
			printf("]\n");
			++y;
		}
		//printf("[%s]\n", str[5][5]);
		//printf("------\n");
		//printf("[%s]\n", line);
		//printf("[%i]\n", ret);
		free(line);
	}
	return (0);
}

