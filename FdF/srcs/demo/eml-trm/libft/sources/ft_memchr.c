/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 11:00:19 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/12 14:23:49 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (((char *)s)[i] == (char)c)
				return (&(((char *)s)[i]));
			i++;
		}
	}
	return (NULL);
}
