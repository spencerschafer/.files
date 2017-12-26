/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:11:50 by etermeau          #+#    #+#             */
/*   Updated: 2014/12/31 00:15:52 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../includes/fdf.h"

int		ft_check_line(t_point ****tab, int i)
{
	int		t;
	int		j;

	t = 0;
	while ((*tab)[i])
	{
		j = 0;
		while ((*tab)[i][j])
			j++;
		t = j;
		if ((*tab)[i + 1])
		{
			i++;
			j = 0;
			while ((*tab)[i][j])
				j++;
		}
		if (j < t)
			ft_code_erreur(4);
		i++;
	}
	if (j == 0)
		return (-1);
	return (0);
}

int		ft_check_map(t_point ****tab)
{
	if (ft_check_line(tab, 0) != 0)
	{
		//prints "Invalid map\n"
		ft_code_erreur(4); // FILE: see below
	}
	else
		ft_fdf(tab);
	return (0);
}

void	ft_code_erreur(int code)
{
	if (code == 0)
		ft_putstr_fd("usage : ./fdf [file]\n", 2);
	else
	{
		ft_putstr_fd("ERROR: ", 2);
		if (code == 1)
			ft_putstr_fd("Can't open file\n", 2);
		else if (code == 2)
			ft_putstr_fd("Malloc error\n", 2);
		else if (code == 3)
			ft_putstr_fd("Variable error\n", 2);
		else if (code == 4)
			ft_putstr_fd("Invalid map\n", 2);
	}
	exit (0);
}
