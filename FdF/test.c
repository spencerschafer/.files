/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:26:29 by sschafer          #+#    #+#             */
/*   Updated: 2017/08/11 17:07:52 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf()
#include "libft.h" //libft functions
#include <unistd.h> //read()
#include <fcntl.h>
#include "get_next_line.h" //BUFF_SIZE

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		int 		fd;
		int			ret;
		char 		*line;

		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("[%s]\n", line);
			free(line);
		}
		//printf("------\n");
		//printf("[%s]\n", line);
		printf("[%i]\n", ret);
		free(line);
	}
	return (0);
}
