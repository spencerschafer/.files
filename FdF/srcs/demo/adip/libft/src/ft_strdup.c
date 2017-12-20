/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 09:53:55 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:52:19 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int		len;
	unsigned int		i;
	char				*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(len + 1));
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
