/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 14:10:05 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/03 10:19:30 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <mlx.h>
#include "../includes/fdf.h"

void		ft_draw_tab(t_point ****tab, int i)
{
	int		j;

	while ((*tab)[i])
	{
		j = 0;
		while ((*tab)[i][j + 1])
		{
			ft_draw_straight(i, j, tab);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while ((*tab)[i][j])
	{
		while ((*tab)[i + 1])
		{
			ft_draw_straight2(i, j, tab, 0);
			i++;
		}
		i = 0;
		j++;
	}
}

void		ft_draw_straight(int i, int j, t_point ****tab)
{
	int		y;
	int		x;
	int		x1;
	int		y1;
	int		x2;

	x1 = (*tab)[i][j]->x;
	y1 = (*tab)[i][j]->y;
	x2 = (*tab)[i][j + 1]->x;
	x = x1;
	while (x <= x2)
	{
		y = (y1 + ((((*tab)[i][j + 1]->y) - y1) * (x - x1) / (x2 - x1)));
		if ((*tab)[i][j]->z >= 5 && (*tab)[i][j + 1]->z >= 10)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0xE0FFFF);
		else if ((*tab)[i][j]->z < 0 && (*tab)[i][j + 1]->z < 0)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0x0000FF);
		else if ((*tab)[i][j]->z == 0 && (*tab)[i][j + 1]->z == 0)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0x9ACD32);
		else
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0xEE82EE);
		x++;
	}
}

void		ft_draw_straight2(int i, int j, t_point ****tab, int y2)
{
	int		y;
	int		x;
	int		x1;
	int		y1;
	int		x2;

	x2 = (*tab)[i][j]->x;
	y2 = (*tab)[i][j]->y;
	y1 = (*tab)[i + 1][j]->y;
	x1 = (*tab)[i + 1][j]->x;
	x = x1;
	while (x <= x2)
	{
		y = (y1 + ((y2 - y1) * (x - x1) / (x2 - x1)));
		if ((*tab)[i][j]->z >= 5 && (*tab)[i + 1][j]->z >= 10)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0xE0FFFF);
		else if ((*tab)[i][j]->z < 0 && (*tab)[i][j + 1]->z < 0)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0x0000FF);
		else if ((*tab)[i][j]->z == 0 && (*tab)[i + 1][j]->z == 0)
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0x9ACD32);
		else
			mlx_pixel_put(ENV->mlx, ENV->win, x, y, 0xEE82EE);
		x++;
	}
}
