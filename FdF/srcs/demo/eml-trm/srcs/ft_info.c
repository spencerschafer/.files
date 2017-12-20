/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:13:16 by etermeau          #+#    #+#             */
/*   Updated: 2015/01/20 10:20:06 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/fdf.h"

static t_point	*ft_structup(char *src, int x, int y)
{
	int			len;
	char		*dst;
	t_point		*new_pos;

	len = 0;
	if (!src)
		ft_code_erreur(3);
	while (src[len] != ' ' && src[len])
		len++;
	if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
		ft_code_erreur(2);
	ft_strncpy(dst, src, len);
	dst[len] = '\0';
	if (!(new_pos = (t_point *)malloc(sizeof(t_point))))
		ft_code_erreur(2);
	new_pos->x = x;
	new_pos->y = y;
	new_pos->z = ft_atoi(dst) * 1.75;
	free (dst);
	return (new_pos);
}

size_t			count_elem(char *str)
{
	int			i;
	size_t		elem;

	i = 0;
	elem = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i])
			elem++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (elem);
}

void			ft_no_space(char *line, bool b)
{
	int			j;
	int			i;

	j = 0;
	i = 0;
	while (line[j])
	{
		if (line[i] != ' ' && line[i])
			i++;
		while (line[i] == ' ' && line[i])
		{
			b = 1;
			i++;
		}
		j++;
	}
	if (b == 0)
		ft_code_erreur(4);
}

t_point			**ft_attribut(char *line, int y_pos, int x_pos)
{
	t_point		**pos;
	t_point		*tmp;
	int			i;

	i = 0;
	if (!(pos = (t_point **)malloc((count_elem(line) + 1) * sizeof(t_point *))))
		ft_code_erreur(2);
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		tmp = ft_structup(line + i, x_pos, y_pos);
		if (line[i] == 0 && x_pos == 0 && tmp == NULL)
			pos[0] = 0;
		else if (tmp != NULL)
			pos[x_pos++] = tmp;
		tmp = NULL;
		while (line[i] != ' ' && line[i])
			i++;
	}
	pos[x_pos] = 0;
	return (pos);
}
