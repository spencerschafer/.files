/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:48:47 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 06:52:00 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*newstr;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = ft_memalloc(len + 1);
	if (newstr != NULL)
	{
		newstr = ft_strcat(newstr, s1);
		newstr = ft_strcat(newstr, (char *)s2);
		return (newstr);
	}
	return (NULL);
}
