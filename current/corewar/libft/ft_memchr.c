/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:15:57 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/10 11:18:58 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *ptr_s;

	ptr_s = (unsigned char *)s;
	while (n--)
	{
		if (*ptr_s == (unsigned char)c)
		{
			return (ptr_s);
		}
		ptr_s++;
	}
	return (NULL);
}
