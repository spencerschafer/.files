/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:33:50 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/30 16:18:57 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	ctr;
	char	*ptr_d;
	char	*ptr_s;

	ctr = 0;
	ptr_d = dst;
	ptr_s = (char *)src;
	while (ctr < n)
	{
		ptr_d[ctr] = ptr_s[ctr];
		ctr++;
	}
	return (ptr_d);
}
