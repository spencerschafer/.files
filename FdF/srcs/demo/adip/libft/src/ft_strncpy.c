/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:52:59 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:48:32 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while ((str[i] != '\0') && (i < n))
	{
		dest[i] = str[i];
		i++;
	}
	if (i < n)
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	else
		dest[++i] = '\0';
	return (dest);
}
