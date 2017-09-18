/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:24:41 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/08 13:40:21 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		new_str[len] = f(len, s[len]);
		len++;
	}
	return (new_str);
}
