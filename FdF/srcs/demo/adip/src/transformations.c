/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:36:00 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 14:50:33 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_vert(t_v3d *v, t_obj *o)
{
	v->x += o->loc.x;
	v->y += o->loc.y;
	v->z += o->loc.z;
}

void	translate_object(t_obj *o, int x, int y, int z)
{
	o->loc.x += x;
	o->loc.y += y;
	o->loc.z += z;
}

void	scale_object(t_obj *o, float x, float y, float z)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < o->rows)
	{
		col = 0;
		while (col < o->cols)
		{
			o->v[row][col].x *= x;
			o->v[row][col].y *= y;
			o->v[row][col].z *= z;
			++col;
		}
		++row;
	}
}

void	scale_oz(t_obj *o, float oz)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (row < o->rows)
	{
		col = 0;
		while (col < o->cols)
		{
			o->oz[row][col] *= oz;
			++col;
		}
		++row;
	}
}
