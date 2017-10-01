/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:03:44 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/02 13:28:19 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s_ptr;
	char	*d_ptr;
	size_t	ctr;

	s_ptr = (char *)src;
	d_ptr = (char *)dst;
	ctr = 0;
	if (d_ptr < s_ptr)
		while (ctr < len)
		{
			d_ptr[ctr] = s_ptr[ctr];
			ctr++;
		}
	else
	{
		ctr = len - 1;
		while ((long long)ctr >= 0)
		{
			d_ptr[ctr] = s_ptr[ctr];
			ctr--;
		}
	}
	return (dst);
}
