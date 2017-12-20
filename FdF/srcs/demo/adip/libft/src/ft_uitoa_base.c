/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:37:54 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:37:58 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	convert_decimal_hex(size_t n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

static char	*my_strjoinchar(char *str, char c)
{
	char	*new;
	char	*temp;

	new = (char *)malloc(ft_strlen(str) + 2);
	temp = new;
	while (*str != '\0')
		*temp++ = *str++;
	*temp++ = c;
	*temp = '\0';
	return (new);
}

char		*ft_uitoa_base(size_t value, int base)
{
	char	*temp;

	while (value > 0)
	{
		temp = my_strjoinchar(temp, convert_decimal_hex(value % base));
		value /= base;
	}
	return (ft_strrev(temp));
}
