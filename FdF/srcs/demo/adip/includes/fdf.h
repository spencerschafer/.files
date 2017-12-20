/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:21:09 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:51 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

# define PTR_SIZE 	sizeof(uintptr_t)
# define WIN_X		1600
# define WIN_Y		900
# define MACOSX

# ifdef MACOSX
#  define ESC_KEY			0x35
#  define PLUS_KEY			0x18
#  define MINUS_KEY			0x1B
#  define ButtonPress		4
#  define ButtonRelease		5
#  define MotionNotify		6
#  define ButtonPressMask	(1L<<2)
#  define ButtonReleaseMask	(1L<<3)
#  define PointerMotionMask	(1L<<6)
# else
#  define ESC_KEY	0xFF1B
#  define PLUS_KEY	0x3D
#  define MINUS_KEY	0x2D
# endif

typedef struct
{
	int		x;
	int		y;
}			t_v2d;

typedef struct
{
	float	x;
	float	y;
	float	z;
	int		colour;
}			t_v3d;

typedef struct
{
	int		button1;
	int		button2;
	int		button3;
	t_v2d	v;
}			t_mouse;

typedef struct
{
	t_v3d	**v;
	size_t	rows;
	size_t	cols;
	float	**oz;
	t_v3d	loc;
	t_v3d	rot;
	t_v3d	scale;
}			t_obj;

typedef struct
{
	void	*mlx;
	void	*win;
	t_obj	o;
	void	*img;
	char	*i_data;
	int		pd;
	int		l_size;
	t_mouse	m;
}			t_env;

typedef struct
{
	t_obj	*o;
	t_v3d	v;
	size_t	row;
	size_t	col;
	float	rx;
	float	ry;
}			t_rot;

/*
 *	src/objects.c
 */
int		construct_object(char *file_name, t_obj *o);

/*
 *	src/transforamtions.c
 */
void	translate_vert(t_v3d *v, t_obj *o);
void	rotate_object(t_obj *o, float x, float y);
void	translate_object(t_obj *i, int x, int y, int z);
void	scale_object(t_obj *o, float x, float y, float z);
void	scale_oz(t_obj *o, float oz);

/*
 *	src/draw.c
 */
int		in_frame(float *x, float *y);
int		draw_line(t_env *e, t_v3d v0, t_v3d v1, int z);
void	draw_vert(t_env *e, t_v3d *p, int swap_xy);
void	draw_object(t_env *e, size_t row, size_t col);

void	normalize_object(t_obj *o);
void	object_init(t_obj *o);

/*
 *	src/hooks.c
 */
int		key_pressed(int key, t_env *env);
int		mouse_event(int button, int x, int y, t_env *e);
int		mouse_down(int button, int x, int y, t_env *e);
int		mouse_up(int button, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);

# endif
