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
#include <fcntl.h>

char ***vector(char ***origin, char *src)
{
	int x;
	int y;
	char	**temp;
	char 	***graph;

	if (origin != NULL)
	{
		y = 0;
		while (origin[y])
			++y;
		graph = (char ***)malloc(sizeof(char **) * (y + 2));

		//copying exisiting values
		//iterating through y values
		y = 0;
		while (origin[y])
		{
			//counting x values to be added
			x = 0;
			while (origin[y][x])
				++x;

			//mallocing new array containing x values
			graph[y] = (char **)malloc(sizeof(char *) * (x + 1));

			//duplicating current values to new vector
			x = 0;
			while (origin[y][x])
			{
				graph[y][x] = ft_strdup(origin[y][x]);
				++x;
			}
			graph[y][x] = NULL;
			++y;
		}
		//adding new str to original vector
		temp = ft_strsplit(src, ' ');
		graph[y++] = temp;
		graph[y] = NULL;
	}
	else
	{
		y = 0;
		graph = (char ***)malloc(sizeof(char **) * (y + 2));
		x = 0;
		graph[y++] = ft_strsplit(src, ' ');
		graph[y] = NULL;
	}
	free(origin);
	return (graph);	
}

/*
 * [create new vector with size of original vector size + 1]
 * [copy exisiting values of original vector to new vector]
 * [add new array to current vector]
 * [split array to add to vector]
 * [add null]
 */

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
			str = vector(str, line);
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
		//printf("------\n");
		//printf("[%s]\n", line);
		//printf("[%i]\n", ret);
		free(line);
	}
	return (0);
}

