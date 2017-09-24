/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 12:42:31 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/21 16:05:17 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t len_little;

	i = 0;
	len_little = ft_strlen((char *)little);
	if (len_little == 0)
		return ((char *)big);
	while ((big[i] != '\0') && (i < len))
	{
		if ((len - i) < len_little)
			return (NULL);
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
