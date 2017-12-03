/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:26:00 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/19 15:07:22 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int 	j;
	int 	counter;
	char	*newstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s) - 1;
	counter = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		++i;
	if (s[i] == '\0')
		return (newstr = ft_strnew(0));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		--j;
	if ((newstr = ft_strnew(j - i + 1)) == NULL)
		return (NULL);
	while (i <= j)
		newstr[counter++] = s[i++];
	newstr[counter] = '\0';
	return (newstr);
}
