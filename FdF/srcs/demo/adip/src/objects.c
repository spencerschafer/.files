/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:20:04 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:48:50 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	count_lines(char *file_name)
{
	size_t	lines;
	char	c;
	int		fd;

	lines = 0;
	fd = open(file_name, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			++lines;
	close(fd);
	return (lines);
}

static void		insert_data(t_obj *o, size_t row, size_t col, char *line)
{
	char	*tmp;

	o->v[row][col].x = col;
	o->v[row][col].y = row;
	o->v[row][col].z = ft_atoi(line);
	o->oz[row][col] = o->v[row][col].z;
	if ((tmp = ft_strchr(line, ',')))
	{
		tmp += 3;
		o->v[row][col].colour = ft_atoi_hex(tmp);
	}
	else
		o->v[row][col].colour = 0;
}

static void		fill_rows(char *file_name, t_obj *o)
{
	size_t			row;
	size_t			col;
	char			*line;
	split_string_t	split;
	int				fd;

	row = 0;
	fd = open(file_name, O_RDONLY);
	while ((ft_gnl(fd, &line) > 0) && row < o->rows)
	{
		split = ft_nstrsplit(line, ' ');
		o->v[row] = (t_v3d *)malloc(sizeof(t_v3d) * split.words);
		o->oz[row] = (float *)malloc(sizeof(float) * split.words);
		col = 0;
		while (col < split.words)
		{
			insert_data(o, row, col, split.strings[col]);
			++col;
		}
		++row;
	}
	o->cols = split.words;
	close(fd);
	ft_printf("Grid:: %d rows x %d columbs\n", row, col);
}

int				construct_object(char *file_name, t_obj *o)
{
	o->rows = count_lines(file_name);
	o->v = (t_v3d **)malloc(sizeof(t_v3d *) * o->rows);
	o->oz = (float **)malloc(sizeof(float *) * o->rows);
	fill_rows(file_name, o);
	ft_putendl("Construction successful");
	return (0);
}
