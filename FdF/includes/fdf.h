#ifndef FDF_H

# define FDF_H
# include <libft.h>
# include <mlx.h>

char ***create_matrix(char ***src, char *str);
char ***read_file(char ***src, char *argv);
void	draw_line(void *mlx, void *window, int x0, int y0, int z0, int x1, int y1, int z1);
void	parse_matrix(void *mlx, void *window, char ***matrix);

#endif
