void	draw_line(int x0, int y0, int x1, int y1, int z)
{
	//TODO
	int x0;
	int y0;

	int x1;
	int y1;

	// start point
	x0 = 0;
	y0 = 0;

	// end point
	x1 = #;
	y1 = #;


	int dx;
	int dy;

	// determining delta values (gradients)
	dx = x1 - x0;
	dy = y1 - y0;


	if (absolute_value(dx)> absolute_value(dy))
		step = absolute_value(dx);
	else
		step = absolute_value(dy);


	int x_increment;
	int y_increment;

	x_increment = dx / (float) step;
	y_increment = dy / (float) step;


	int counter;
	while (counter  < step)
	{
		x += x_increment;
		y += y_increment;
		mlx_pixel_put(round(x), round(y));
		++counter;
	}
}
