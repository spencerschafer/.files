/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 15:00:20 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/08 16:18:42 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	ctr;
	char	*ptr;

	ctr = 0;
	ptr = b;
	while (ctr < len)
	{
		ptr[ctr] = c;
		ctr++;
	}
	return (ptr);
}
