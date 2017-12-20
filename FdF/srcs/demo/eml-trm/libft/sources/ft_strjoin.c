/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 22:17:13 by etermeau          #+#    #+#             */
/*   Updated: 2014/12/09 19:12:57 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		tmp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!tmp)
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp = ft_strcat(tmp, s2);
	}
	return (tmp);
}
