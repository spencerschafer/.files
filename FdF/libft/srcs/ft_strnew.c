/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 08:45:18 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 08:24:39 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		++i;
	}
	return (str);
}
