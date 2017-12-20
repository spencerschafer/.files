/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:15:15 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/14 20:16:27 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	a;

	a = 0;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (0);
	while (a <= size)
	{
		str[a] = 0;
		a++;
	}
	return (str);
}
