/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:59:15 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:26:10 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		int_write(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
	return (1);
}

int		check_not_sign(char *conclusion, char logic)
{
	int		i;

	i = -1;
	while (conclusion[++i] != '\0')
	{
		if (conclusion[i] == '!' && conclusion[i + 1] != '\0' \
				&& conclusion[i + 1] == logic)
			return (1);
	}
	return (0);
}

int		sign_search(char *str, char *find)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_strchr(find, str[i]) != NULL)
			return (TRUE);
	}
	return (FALSE);
}

int		str_value(char *str)
{
	if (ft_strcmp(str, "true") == 0)
		return (TRUE);
	else if (ft_strcmp(str, "false") == 0)
		return (FALSE);
	else if (ft_strcmp(str, "undetermined") == 0)
		return (UNDETERMINED);
	return (-1);
}

char	*str_undef(char logic)
{
	char	str[50];
	char	s[100];

	bzero(str, 50);
	bzero(s, 100);
	sprintf(str, KBLUE "\t%c" RESET " is " KRED "UNDEFINED " RESET, logic);
	ft_strcat(s, str);
	bzero(str, 50);
	sprintf(str, "....Hence " KBLUE "%c" RESET " is " KRED "FALSE" RESET "\n", logic);
	ft_strcat(s, str);
	return (strdup(s));
}
