/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:42:59 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/08 13:41:54 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int result;

	if (!s1 || !s2)
		return (0);
	result = ft_strncmp(s1, s2, n);
	if (result == 0)
		return (1);
	else
		return (0);
}
