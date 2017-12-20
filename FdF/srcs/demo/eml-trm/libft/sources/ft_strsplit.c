/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 10:22:31 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/23 19:06:34 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcdup(char const *str, char c)
{
	int		i;
	int		len;
	char	*dst;

	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (!(dst = (char *)malloc(sizeof(char *) * (len))))
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_count_split(char const *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			n++;
		while (str[i] != c && str[i])
			i++;
	}
	return (n);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**tab;
	char	*tmp;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (str == NULL)
		return (NULL);
	tab = (char **)malloc((ft_count_split(str, c) + 1) * sizeof(char *));
	while (str[i])
	{
		while (str[i] == c)
			i++;
		tmp = ft_strcdup(str + i, c);
		i += ft_strlen(tmp);
		if (str[i] == 0 && y == 0 && tmp[0] == 0)
			tab[0] = 0;
		else if (tmp[0] != 0)
			tab[y++] = ft_strdup(tmp);
		free(tmp);
	}
	tab[y] = 0;
	return (tab);
}
