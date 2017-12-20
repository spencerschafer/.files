/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:20:17 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 14:37:38 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rot(t_rot *r, t_obj *o)
{
	r->v.y = o->v[r->row][r->col].y * cos(r->rx);
	r->v.y += o->v[r->row][r->col].z * sin(r->rx);
	r->v.z = o->v[r->row][r->col].z * cos(r->rx);
	r->v.z -= o->v[r->row][r->col].y * sin(r->rx);
	o->v[r->row][r->col].y = r->v.y;
	o->v[r->row][r->col].z = r->v.z;
	r->v.x = o->v[r->row][r->col].x * cos(r->ry);
	r->v.x -= o->v[r->row][r->col].z * sin(r->ry);
	r->v.z = o->v[r->row][r->col].x * sin(r->ry);
	r->v.z += o->v[r->row][r->col].z * cos(r->ry);
	o->v[r->row][r->col].x = r->v.x;
	o->v[r->row][r->col].z = r->v.z;
}

void		rotate_object(t_obj *o, float x, float y)
{
	t_rot	r;

	r.rx = x * 0.0174;
	r.ry = y * 0.0174;
	r.row = 0;
	while (r.row < o->rows)
	{
		r.col = 0;
		while (r.col < o->cols)
		{
			rot(&r, o);
			++r.col;
		}
		++r.row;
	}
}
