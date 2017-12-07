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

char ***vector(char ***src, char *str)
{
	int x;
	int y;
	//char	**temp; 
	char	**new_str;
	char 	***graph;

	y = 0;
	if (src != NULL)
	{
		while (src[y])
			++y;
	}
	graph = (char ***)malloc(sizeof(char **) * (y + 2));

	if (y > 0)
	{
		//copying exisiting values
		//iterating through y values
		y = 0;
		while (src[y])
		{
			//counting x values to be added
			x = 0;
			while (src[y][x])
				++x;

			//mallocing new array that will contain the current x values
			graph[y] = (char **)malloc(sizeof(char *) * (x + 1));

			//duplicating current values to new vector
			x = 0;
			while (src[y][x])
			{
				graph[y][x] = ft_strdup(src[y][x]);
				++x;
			}
			graph[y][x] = NULL;
			++y;
		}

		//adding new str to srcal vector
		new_str = ft_strsplit(str, ' ');
		graph[y++] = new_str;
		graph[y] = NULL;
	}
	else
	{
		graph[y++] = ft_strsplit(str, ' ');
		graph[y] = NULL;
	}
	free(src);
	return (graph);	
}

/*
 * [create new vector with size of src vector size + 1]
 * [copy exisiting values of src vector to new vector]
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
		printf("[%s]\n", str[4][5]);
		//printf("------\n");
		//printf("[%s]\n", line);
		//printf("[%i]\n", ret);
		free(line);
	}
	return (0);
}

