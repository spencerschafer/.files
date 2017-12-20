/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:19:41 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 13:19:43 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_object(t_obj *o)
{
	size_t	row;
	size_t	col;
	float	orign[2];

	orign[0] = o->cols / 2;
	orign[1] = o->rows / 2;
	row = 0;
	while (row < o->rows)
	{
		col = 0;
		while (col < o->cols)
		{
			o->v[row][col].x -= orign[0];
			o->v[row][col].y -= orign[1];
			++col;
		}
		++row;
	}
}

void	object_init(t_obj *o)
{
	o->rows = 0;
	o->cols = 0;
	o->loc.x = 0;
	o->loc.y = 0;
	o->loc.z = 0;
	o->rot.x = 0;
	o->rot.y = 0;
	o->rot.z = 0;
	o->scale.x = 1;
	o->scale.y = 1;
	o->scale.z = 1;
}
