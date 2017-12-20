/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 14:38:17 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/14 20:17:51 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	i = start;
	if (s)
	{
		tmp = (char *)malloc(len + 1);
		if (!tmp)
			return (NULL);
		while (i < len + start)
		{
			tmp[i - start] = s[i];
			i++;
		}
		tmp[i - start] = '\0';
	}
	return (tmp);
}
