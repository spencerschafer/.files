#include <math.h>
#include <stdlib.h>
#include "fdf.h"
#include <mlx.h>

void	draw_line(void *mlx, void *window, int x0, int y0, int z0, int x1, int y1, int z1)
{
	//TODO
	int dx;
	int dy;
	int step;
	int absolute_dx;
	int absolute_dy;

	// determining delta values (gradients)
	dx = x1 - x0;
	dy = y1 - y0;
	
	absolute_dx = abs(dx);
	absolute_dy = abs(dy);
		

	if (absolute_dx > absolute_dy)
		step = absolute_dx;
	else
		step = absolute_dy;


	int x_increment;
	int y_increment;

	x_increment = dx / (float) step;
	y_increment = dy / (float) step;


	int counter;
	counter = 0;
	while (counter  < step + 100)
	{
		x0 += x_increment;
		y0 += y_increment;
		mlx_pixel_put(mlx, window, 626 - round(x0), 375 - round(y0), 0xFFFFFF);
		++counter;
	}
}
