/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 10:08:31 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/10 14:14:13 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t temp;

	i = 0;
	temp = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			temp = i;
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	else if (i > 0 && (s[temp] == c))
		return ((char *)(s + temp));
	return (NULL);
}
