/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 12:46:27 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/27 11:17:55 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**Format: ARRAY[[word0], [word1], [word2], word[3], '\0']
** ...
**Count the number of words in string.
**Malloc first array to number of words, +1 for '\0'.
**Malloc first array of main array to len of first word.
**Iterate through delimiter.
**Copy word to array[0] until delimiter is reached.
**Iterate through delimiter.
**Malloc second array of main array to len of second word.
**Starting from where previous iteration of delimiter ended, copy
**string[previous iteration] to array[1] until delimiter is reached.
**Do this until no more words remain.
**Place '\0' in final array of main array.
**Return **mainarray.
*/

char		**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
	int		wordcount;
	char	**newstr;

	j = 0;
	wordcount = ft_countwords(s, c);
	newstr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if ((!s) || (!newstr) || (!s) || (wordcount == -1))
		return (NULL);
	while (j < wordcount)
	{
		k = 0;
		if (!(newstr[j] = ft_strnew(ft_wordlen(s, c))))
			return (NULL);
		while (*s == c)
			s++;
		while ((*s != c) && *s != '\0')
			newstr[j][k++] = *s++;
		newstr[j++][k] = '\0';
	}
	newstr[j] = NULL;
	return (newstr);
}
