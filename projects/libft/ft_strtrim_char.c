/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:40:16 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/21 12:42:43 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim_char(char const *s, char delimiter)
{
	size_t	i;
	size_t	j;
	size_t	counter;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	counter = 0;
	while (s[i] == delimiter)
		i++;
	if (s[i] == '\0')
		return (newstr = ft_strnew(0));
	while (s[j] == delimiter)
		j--;
	if ((newstr = ft_strnew(j - i + 1)) != NULL)
	{
		while (i <= j)
			newstr[counter++] = s[i++];
		newstr[counter] = '\0';
	}
	return (newstr);
}
