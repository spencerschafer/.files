/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:30:45 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/13 17:03:22 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		a;
	int		i;
	int		j;
	char	*str;

	a = 0;
	i = 0;
	str = NULL;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] && (s[i] < 33 || s[i] >= 126))
			i++;
		while (s[j] && (s[j] < 33 || s[j] >= 126))
			j--;
		str = malloc(sizeof((j - i) + 1));
		if (!str)
			return (NULL);
		while (i <= j)
			str[a++] = s[i++];
		str[a] = '\0';
	}
	return (str);
}
