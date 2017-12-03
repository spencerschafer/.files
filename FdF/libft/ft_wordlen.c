/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:27:11 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 12:30:45 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(char const *s, char delimiter)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == delimiter)
		++i;
	while ((s[i] != delimiter) && (s[i] != '\0'))
	{
		++i;
		++count;
	}
	return (count);
}
