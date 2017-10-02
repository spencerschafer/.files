/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:26:42 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/24 17:44:01 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	ctr_s;
	size_t	ctr_e;

	if (!s)
		return (NULL);
	ctr_s = 0;
	ctr_e = ft_strlen(s);
	while ((s[ctr_s] == ' ' || s[ctr_s] == '\n'
				|| s[ctr_s] == '\t') && ctr_s < ctr_e)
		ctr_s++;
	if (ctr_s == ctr_e)
		return (ft_strnew(0));
	ctr_e--;
	while (s[ctr_e] == ' ' || s[ctr_e] == '\n' || s[ctr_e] == '\t')
		ctr_e--;
	return (ft_strsub(s, ctr_s, (ctr_e - ctr_s + 1)));
}
