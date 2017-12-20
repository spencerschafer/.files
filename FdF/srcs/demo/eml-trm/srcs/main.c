/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:16:04 by etermeau          #+#    #+#             */
/*   Updated: 2016/05/02 10:19:32 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/fdf.h"

int			ft_check_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		//prints "Can't open file\n"
		ft_code_erreur(1); //FILE: ft_erreur.c
	}
	return (fd);
}

void		ft_read_file(char *file, t_point ****tab)
{
	char	*matrix;
	int		line;
	int		fd;

	fd = ft_check_file(file); //FILE: see above
	line = 0;
	//adding each line of file to matrix
	while (get_next_line(fd, &matrix))
		line++;
	close(fd);
	//reopening file
	ft_check_file(file); //FILE: see above
	if (!(*tab = (t_point ***)malloc(sizeof(t_point **) * line) + 1))
	{
		//prints "Malloc error\n"
		ft_code_erreur(2);  //FILE: ft_erreur.c
	}
	line = 0;
	//TODO
	// something to do with adding each line of matrix to the line of tab
	// each value contained in a line is a tab struct containing values.
	// similiar to create_matrix
	while (get_next_line(fd, &matrix))
	{
		(*tab)[line] = ft_attribut(matrix, line, 0); //FILE: ft_info.c
		ft_no_space(matrix, 0); //FILE: ft_info.c
		line++;
		free(matrix);
	}
	(*tab)[line] = NULL;
}

int			main(int ac, char *av[])
{
	//contains x, y, z, mlx, window
	t_point	***data; //FILE: fdf.h
	
	//initialising struct
	data = NULL;
	if (ac == 2)
	{
		//TODO
		//similar to create_matrix	
		ft_read_file(av[1], &data); //FILE: see above
		if (data == NULL)
			return (0);
		//TODO
		//similar to parse_matrix
		//ft_check_map calls ft_fdf.c which calls the  various draw functions
		ft_check_map(&data); //FILE: ft_erreur.c
	}
	else
	{
		//prints "usage : ./fdf [file]\n"
		ft_code_erreur(0); //FILE: ft_erreur.c
	}
	return (0);
}
