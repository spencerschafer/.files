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
#include "fdf.h"
/*
** [create new vector with size of src vector size + 1]
** [copy exisiting values of src vector to new vector]
** [add new array to current vector]
** [split array to add to vector]
** [add null]
**/

char ***create_matrix(char ***src, char *str)
{
	int x;
	int y;
	//char	**temp; //to free memory
	char	**new_str;
	char 	***matrix;

	y = 0;
	if (src != NULL)
	{
		while (src[y])
			++y;
	}
	matrix = (char ***)malloc(sizeof(char **) * (y + 2));

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
			matrix[y] = (char **)malloc(sizeof(char *) * (x + 1));

			//duplicating current values to new vector
			x = 0;
			while (src[y][x])
			{
				matrix[y][x] = ft_strdup(src[y][x]);
				++x;
			}
			matrix[y][x] = NULL;
			++y;
		}

		//adding new str to srcal vector
		new_str = ft_strsplit(str, ' ');
		matrix[y++] = new_str;
		matrix[y] = NULL;
	}
	else
	{
		matrix[y++] = ft_strsplit(str, ' ');
		matrix[y] = NULL;
	}
	free(src);
	return (matrix);
}
