/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:32:01 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/31 10:02:42 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *ptrs1;
	const char *ptrs2;

	ptrs1 = s1;
	ptrs2 = s2;
	while (n--)
	{
		if (*ptrs1 != *ptrs2)
		{
			return ((unsigned char)*ptrs1 - (unsigned char)*ptrs2);
		}
		ptrs1++;
		ptrs2++;
	}
	return (0);
}
