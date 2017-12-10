#include "fdf.h"
#include <fcntl.h>
#include "libft.h"

//get_next_line values
char ***read_file(char ***map, char *argv)
{
	int			ret;
	int			fd;
	//map valuess
	char 		*line;

	//opening file
	fd = open(argv, O_RDONLY);

	//creating map of coordinates
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map = create_matrix(map, line);
		free(line);
	}
	free(line);
	return (map);
}
