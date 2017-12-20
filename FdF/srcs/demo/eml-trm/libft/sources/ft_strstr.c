/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:20:47 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/06 15:49:33 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[n])
			n++;
		else
			n = 0;
		i++;
		if (s2[n] == '\0')
			return (&(((char *)s1)[i - n]));
	}
	return (NULL);
}
