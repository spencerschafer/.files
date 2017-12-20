/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:37:46 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:53 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_pressed(int key, t_env *e)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int			mouse_down(int button, int x, int y, t_env *e)
{
	if (button < 4)
	{
		e->m.button1 = 0;
		e->m.button2 = 0;
		e->m.button3 = 0;
		if (button == 1)
			e->m.button1 = 1;
		else if (button == 2)
			e->m.button2 = 1;
		else if (button == 3)
			e->m.button3 = 1;
		e->m.v.x = x;
		e->m.v.y = y;
	}
	else
	{
		if (button == 4)
			scale_object(&e->o, 1.05, 1.05, 1.05);
		else
			scale_object(&e->o, 0.95, 0.95, 0.95);
		draw_object(e, -1, 0);
	}
	return (0);
}

int			mouse_up(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 1)
		e->m.button1 = 0;
	else if (button == 2)
		e->m.button2 = 0;
	return (0);
}

int			mouse_move(int x, int y, t_env *e)
{
	t_v2d			d;
	static size_t	skip = 0;

	if (skip == 2)
	{
		if (e->m.button1 || e->m.button2 || e->m.button3)
		{
			d.x = x - e->m.v.x;
			d.y = y - e->m.v.y;
			e->m.v.x = x;
			e->m.v.y = y;
			if (e->m.button1)
				translate_object(&e->o, d.x, d.y, 0);
			else if (e->m.button2)
				rotate_object(&e->o, d.y / 15.0, d.x / -15.0);
			draw_object(e, -1, 0);
		}
		skip = 0;
	}
	++skip;
	return (0);
}
