#include "fdf.h"
#include <math.h> //abs, fabs, round
#include <stdio.h>

/*
 * end point is x + 1, also y + 1;
 */

//counting length of strings (x)  & counts amount of strings (y)
void	find_dimensions(char ***matrix, int *x, int *y)
{
	//TODO: error check file: length of each string must be equal
	int x_counter;
	int y_counter;

	x_counter = 0;
	y_counter = 0;
	while (matrix[y_counter][x_counter])
		++x_counter;
	while (matrix[y_counter])
		++y_counter;
	*x = x_counter;
	*y = y_counter;
}


void	parse_matrix(char ***matrix)
{
	//max values
	int x_max;
	int y_max;

	//start point
	int x_start;
	int y_start;
	int z_start;

	//end point
	int x_end;
	int y_end;
	int z_end;

	//TODO: see if intialisation of x_max/y_max is necessary i.e remove "= 0"
	x_max = 0;
	y_max = 0;

	//setting x and y max values
	find_dimensions(matrix, &x_max, &y_max);

	y_start = 0;
	y_end = 0;
	while (y_end < y_max)
	{
		//draw horizontal lines
		x_start = 0;
		x_end = x_start + 1;
		y_end = y_start;
		//TODO: can remove +1 and increment counter in loop conditional
		//i.e. while (++x_end < x_max)
		while (x_end < x_max)
		{
			//TODO: see if y_value is necessary here as it remains the same throughout loop
			z_start = ft_atoi(matrix[y_start][x_start]);
			z_end = ft_atoi(matrix[y_end][x_end]);

			draw_line(x_start, y_start, z_start, x_end, y_end, z_end);

			++x_start;
			++x_end;
		}

		//draw vertical lines
		x_start = 0;
		x_end = 0;
		y_end = y_start + 1;
		//TODO: can remove +1 and increment counter in loop conditional
		//i.e. while (++x_end < x_max)
		while (x_end < x_max)
		{
			//TODO: see if y_value is necessary here as it remains the same throughout loop
			z_start = ft_atoi(matrix[y_start][x_start]);
			z_end = ft_atoi(matrix[y_end][x_end]);

			draw_line(x_start, y_start, z_start, x_end, y_end, z_end);

			++x_start;
			++x_end;
		}
		++y_start;
	}
}
