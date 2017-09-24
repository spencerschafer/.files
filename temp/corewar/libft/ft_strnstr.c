/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:30:08 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/09 08:16:08 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	checklen(char *hs, char *nd, size_t n)
{
	size_t ctr;

	ctr = 0;
	while ((hs[ctr] == nd[ctr]) && nd[ctr] && ctr < n)
	{
		ctr++;
	}
	return (ctr);
}

char			*ft_strnstr(const char *hs, const char *nd, size_t n)
{
	size_t ctr;

	ctr = 0;
	if (ft_strlen(nd) == 0)
		return ((char *)hs);
	while (*hs != '\0' && ctr < n)
	{
		if (ft_strlen(nd) > (n - ctr))
			break ;
		if (*hs == *nd)
		{
			if (checklen((char *)hs, (char *)nd, n) >= ft_strlen(nd))
			{
				return ((char *)hs);
			}
		}
		hs++;
		ctr++;
	}
	return (NULL);
}
