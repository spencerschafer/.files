/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:47:00 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/21 15:50:40 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countwords(char const *s, char delimiter)
{
	size_t	i;
	size_t	len;
	int		count;
	char	*newstr;

	i = 0;
	count = 0;
	newstr = ft_strtrim_char(s, delimiter);
	if (newstr == NULL)
		return (-1);
	len = ft_strlen(newstr);
	if (len == 0)
		return (count);
	count++;
	while (newstr[i] != '\0')
	{
		if ((newstr[i] == delimiter) && (newstr[i - 1] != delimiter))
			count++;
		i++;
	}
	return (count);
}
