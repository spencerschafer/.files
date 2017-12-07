#include "libft.h"
#include "mlx.h"
#include <stdio.h>

/*
 ** Function that closes program window upon 'esc' key being pressed.
 */

int	close(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	int x;
	int y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FdF");
	x = 150;
	y = 150;
	while (x < 250)
		mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
	mlx_key_hook(win, close, 0); // exit program
	mlx_loop(mlx);
}
