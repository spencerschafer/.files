/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:03:05 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:33 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		assign_colour(t_v3d *v, int z)
{
	if (v->colour == 0)
	{
		if (z < 0)
			v->colour = 0x00FFAA00;
		else if (z >= 0 && z < 10)
			v->colour = 0x001141AF;
		else if (z >= 10 && z < 20)
			v->colour = 0x00FF7400;
		else if (z >= 20 && z < 50)
			v->colour = 0x0000CE00;
		else if (z >= 50 && z < 70)
			v->colour = 0x00068306;
		else if (z >= 70)
			v->colour = 0x00185018;
	}
}

static int		draw_line_part2(t_env *e, t_v3d *v0, t_v3d *v1, int *steep)
{
	translate_vert(v0, &e->o);
	translate_vert(v1, &e->o);
	if (!in_frame(&v0->x, &v0->y) && !in_frame(&v1->x, &v1->y))
		return (1);
	*steep = fabsf(v1->y - v0->y) > fabsf(v1->x - v0->x);
	if (*steep)
	{
		ft_float_swap(&(v0->x), &(v0->y));
		ft_float_swap(&(v1->x), &(v1->y));
	}
	if (v0->x > v1->x)
	{
		ft_float_swap(&(v0->x), &(v1->x));
		ft_float_swap(&(v0->y), &(v1->y));
	}
	return (0);
}

static void		calculate_delta(t_v3d *v0, t_v3d *v1, t_v2d *d, int *error)
{
	d->x = v1->x - v0->x;
	d->y = fabsf(v1->y - v0->y);
	*error = (d->x / 2);
}

int				draw_line(t_env *e, t_v3d v0, t_v3d v1, int z)
{
	int		steep;
	int		error;
	int		ystep;
	t_v2d	d;

	assign_colour(&v0, z);
	if (draw_line_part2(e, &v0, &v1, &steep))
		return (0);
	calculate_delta(&v0, &v1, &d, &error);
	if (v0.y < v1.y)
		ystep = 1;
	else
		ystep = -1;
	while (v0.x < v1.x)
	{
		draw_vert(e, &v0, steep);
		error -= (int)d.y;
		if (error < 0)
		{
			v0.y += (int)ystep;
			error += (int)d.x;
		}
		v0.x++;
	}
	return (0);
}
