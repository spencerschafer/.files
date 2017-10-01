/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:47:51 by hstander          #+#    #+#             */
/*   Updated: 2017/08/16 17:22:48 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strcounter(char const *s, char c)
{
	size_t		ctr;
	size_t		s_ctr;

	ctr = 0;
	s_ctr = 0;
	while (s[ctr])
	{
		if (s[ctr] == c || s[ctr] == '\t')
			while (s[ctr] == c || s[ctr] == '\t')
				ctr++;
		if (s[ctr])
		{
			s_ctr++;
			while (s[ctr] && s[ctr] != c && s[ctr] != '\t')
				ctr++;
		}
	}
	return (s_ctr);
}

static size_t	word_len(char const *s, char c)
{
	size_t		ctr;

	ctr = 0;
	while (s[ctr] && s[ctr] != c && s[ctr] != '\t')
		ctr++;
	return (ctr);
}

char			**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		ctr;
	size_t		r_ctr;

	if (!s)
		return (NULL);
	ctr = 0;
	r_ctr = 0;
	ret = (char **)ft_memalloc(sizeof(char **) * (strcounter(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	while (s[ctr])
	{
		if (s[ctr] && s[ctr] != c && s[ctr] != '\t')
		{
			ret[r_ctr] = ft_strsub(s, ctr, word_len(&s[ctr], c));
			r_ctr++;
			ctr += word_len(&s[ctr], c);
		}
		while (s[ctr] && (s[ctr] == c || s[ctr] == '\t'))
			ctr++;
	}
	ret[r_ctr] = NULL;
	return (ret);
}
