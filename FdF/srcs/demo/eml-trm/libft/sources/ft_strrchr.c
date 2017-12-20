/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:50:01 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/07 16:14:41 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(const char *str)
{
	int		q;

	q = 0;
	while (str[q] != '\0')
		q++;
	return (q);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_len(s);
	while (s[i] != c && i != 0)
		i--;
	if (s[i] == c)
		return (&(((char *)s)[i]));
	else
		return (NULL);
}
