/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:19:13 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:34 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			in_frame(float *x, float *y)
{
	if (*x < 10 || *y < 10)
		return (0);
	if (*x > WIN_X + 90 || *y > WIN_Y + 90)
		return (0);
	return (1);
}

void		draw_vert(t_env *e, t_v3d *p, int swap_xy)
{
	size_t	i;

	if (swap_xy)
	{
		if (in_frame(&p->y, &p->x))
		{
			i = (int)p->y * 4 + (int)p->x * e->l_size;
			e->i_data[i] = p->colour;
			e->i_data[++i] = p->colour >> 8;
			e->i_data[++i] = p->colour >> 16;
		}
	}
	else if (in_frame(&p->x, &p->y))
	{
		i = (int)p->x * 4 + (int)p->y * e->l_size;
		e->i_data[i] = p->colour;
		e->i_data[++i] = p->colour >> 8;
		e->i_data[++i] = p->colour >> 16;
	}
}

ssize_t		ft_max(ssize_t v1, ssize_t v2)
{
	if (v1 > v2)
		return (v1);
	else
		return (v2);
}

void		draw_object(t_env *e, size_t row, size_t col)
{
	int		z;

	e->img = mlx_new_image(e->mlx, WIN_X + 100, WIN_Y + 100);
	e->i_data = mlx_get_data_addr(e->img, &(e->pd), &(e->l_size), &z);
	while (++row < e->o.rows)
	{
		col = -1;
		while (++col < e->o.cols)
		{
			if (col + 1 < e->o.cols)
			{
				z = (int)ft_max(e->o.oz[row][col], e->o.oz[row][col + 1]);
				draw_line(e, e->o.v[row][col], e->o.v[row][col + 1], z);
			}
			if (row + 1 < e->o.rows)
			{
				z = (int)ft_max(e->o.oz[row][col], e->o.oz[row + 1][col]);
				draw_line(e, e->o.v[row][col], e->o.v[row + 1][col], z);
			}
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, -50, -50);
	mlx_destroy_image(e->mlx, e->img);
}
