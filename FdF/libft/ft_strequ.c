/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:10:22 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/16 15:41:59 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	value;

	if ((s1 == NULL) || (s2 == NULL))
		return (0);
	value = ft_strcmp(s1, s2);
	return ((value == 0) ? 1 : 0);
}
