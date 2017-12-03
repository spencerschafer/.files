/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 16:18:15 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/18 16:22:53 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		buff_size;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	buff_size = ft_strlen((char *)s);
	if ((new_str = (char *)malloc(sizeof(char) * (buff_size + 1))) == NULL)
		return (NULL);
	while (i < buff_size)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
