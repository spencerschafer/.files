/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:26:29 by sschafer          #+#    #+#             */
/*   Updated: 2017/12/07 13:27:19 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf()
#include "libft.h" //libft functions
#include "mlx.h"
#include <fcntl.h>


/*
 ** Function that closes program window upon 'esc' key being pressed.
 */

int	close(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	dimension(char ***map, int *x, int *y)
{
	int x_c;
	int y_c;

	x_c = 0;
	y_c = 0;
	while (map[y_c][x_c])
		++x_c;
	while (map[y_c])
		++y_c;
	*x = x_c;
	*y = y_c;
}

int				main(int argc, char **argv)
{
	if (argc == 2)
	{
		//x and y values
		int			x;
		int			y;
		
		//mlx values
		void *mlx;
		void *window;

		//get_next_line values
		int 		fd;
		int			ret;

		//map valuess
		char 		*line;
		char		***map = NULL;

		//opening file
		fd = open(argv[1], O_RDONLY);

		//creating map of coordinates
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			map = ft_map(map, line);
			free(line);
		}
		free(line);

		//opening window
		x = 0;
		y = 0;
		dimension(map, &x, &y);
		printf("x: %d\ny: %d\n", x, y);
		mlx = mlx_init();

		/*
			x = 150;
			y = 150;
			while (x < 250)
			mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
		*/
		
		window = mlx_new_window(mlx, x * 28, y * 14 + 11, "FdF");
		mlx_key_hook(window, close, 0); // exit program
		
		//y = 3  : y * 14 : highest value = 0 : total = 42
		//y = 11 : y * 14 : highest value = 0 : total = 154
		//y * 16
		//(y + highest value) * 10
		//
		mlx_loop(mlx);
	}
	return (0);
}

