/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:06:45 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/31 14:25:14 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*new_str;
	int		ctr;

	len = ft_strlen(s);
	new_str = (char *)malloc(len * sizeof(char) + 1);
	if (new_str == NULL)
		return (NULL);
	ctr = 0;
	while (s[ctr])
	{
		new_str[ctr] = s[ctr];
		ctr++;
	}
	new_str[ctr] = '\0';
	return (new_str);
}
