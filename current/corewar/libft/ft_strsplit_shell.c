/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_shell.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 09:01:35 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/28 11:06:04 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strcounter(char const *s, int ctr)
{
	size_t		r_ctr;

	r_ctr = 0;
	while (s[ctr])
	{
		if (s[ctr] == '"')
		{
			ctr++;
			while (s[ctr] && s[ctr] != '"')
				ctr++;
			r_ctr++;
			if (s[ctr])
				ctr++;
		}
		while (s[ctr] && s[ctr] != ' ' && s[ctr] != '"')
			ctr++;
		r_ctr++;
		ctr++;
	}
	return (r_ctr);
}

static char		*get_substr(char const *s, int len)
{
	char		*sub_str;

	if (len == 0)
		return (ft_strnew(0));
	sub_str = ft_strsub(s, 0, len);
	return (sub_str);
}

static void		ss_sub(char **ret, char *s, size_t begin, size_t r_ctr)
{
	int			ctr;

	ctr = 0;
	while (s[ctr])
	{
		begin = ctr;
		if (s[ctr] == '"')
		{
			ctr++;
			begin++;
			while (s[ctr] && s[ctr] != '"')
				ctr++;
			ret[r_ctr] = get_substr(&s[begin], (ctr - begin));
			r_ctr++;
			if (s[ctr])
				ctr++;
			begin = ctr;
		}
		while (s[ctr] && s[ctr] != ' ' && s[ctr] != '"')
			ctr++;
		ret[r_ctr] = get_substr(&s[begin], (ctr - begin));
		r_ctr++;
		ctr++;
	}
	ret[r_ctr] = NULL;
}

char			**ft_strsplit_shell(char *s)
{
	char		**ret;
	size_t		ctr;
	size_t		begin;
	size_t		r_ctr;

	if (!s)
		return (NULL);
	ctr = 0;
	begin = 0;
	r_ctr = 0;
	ret = (char **)ft_memalloc(sizeof(char **) * (strcounter(s, ctr) + 1));
	if (ret == NULL)
		return (NULL);
	ss_sub(ret, s, begin, r_ctr);
	return (ret);
}
