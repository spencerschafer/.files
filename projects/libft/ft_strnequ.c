/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:19:35 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/16 15:41:46 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t value;

	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	value = ft_strncmp(s1, s2, n);
	return ((value == 0) ? 1 : 0);
}
