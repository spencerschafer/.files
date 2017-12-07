/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:24:08 by sschafer          #+#    #+#             */
/*   Updated: 2017/12/07 13:26:49 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** [create new vector with size of src vector size + 1]
** [copy exisiting values of src vector to new vector]
** [add new array to current vector]
** [split array to add to vector]
** [add null]
**/

char ***ft_map(char ***src, char *str)
{
	int x;
	int y;
	//char	**temp; //to free memory
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
