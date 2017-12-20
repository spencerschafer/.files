/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 14:40:51 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:48 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose_event(t_env *e)
{
	draw_object(e, -1, 0);
	return (0);
}

static void	main_hooks(t_env *env)
{
	mlx_key_hook(env->win, key_pressed, env);
	mlx_expose_hook(env->win, expose_event, env);
	mlx_hook(env->win, ButtonPress, ButtonPressMask, mouse_down, env);
	mlx_hook(env->win, ButtonRelease, ButtonReleaseMask, mouse_up, env);
	mlx_hook(env->win, MotionNotify, ButtonPressMask | ButtonReleaseMask |
		PointerMotionMask, mouse_move, env);
}

int			main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
	{
		ft_printf("Usage: ./fdf <file name> <(optional) Z scale factor>\n");
		exit(0);
	}
	object_init(&env.o);
	construct_object(argv[1], &env.o);
	normalize_object(&env.o);
	translate_object(&env.o, WIN_X / 2 + 50, WIN_Y / 2 + 50, 0);
	if (argc == 3)
		scale_oz(&env.o, ft_atoi(argv[2]));
	scale_object(&env.o, 25, 25, 1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "FdF");
	main_hooks(&env);
	draw_object(&env, -1, 0);
	mlx_loop(env.mlx);
	return (0);
}
