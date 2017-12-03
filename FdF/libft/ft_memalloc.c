/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 10:47:34 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/15 08:31:31 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((str = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	while (i < size)
	{
		str[i++] = 0;
	}
	return (str);
}
