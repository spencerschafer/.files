/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:12:15 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/02 12:09:09 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checklen(char *hs, char *nd)
{
	size_t ctr;

	ctr = 0;
	while (hs[ctr] == nd[ctr] && nd[ctr])
	{
		ctr++;
	}
	return (ctr);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;

	len = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			len = checklen((char *)haystack, (char *)needle);
			if (len == ft_strlen(needle))
			{
				return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
