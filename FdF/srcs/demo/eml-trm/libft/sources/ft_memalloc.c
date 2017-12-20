/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:24:14 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/16 19:20:35 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*new;
	char	*tmp;

	new = malloc(sizeof(size));
	tmp = new;
	if (!new || (int)size <= 0)
		return (NULL);
	while ((tmp - new) < (int)size)
		*(tmp++) = 0;
	return (new);
}
