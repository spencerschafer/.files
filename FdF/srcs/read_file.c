#include "fdf.h"
#include <fcntl.h>
#include "libft.h"

//get_next_line values
char ***read_file(char ***src, char *argv)
{
	int			ret;
	int			fd;
	//map valuess
	char 		*line;

	//opening file
	fd = open(argv, O_RDONLY);

	//creating map of coordinates
	while ((ret = ft_get_line(fd, &line)) > 0)
	{
		src = create_matrix(src, line);
		free(line);
	}
	free(line);
	return (src);
}
