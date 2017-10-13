/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:38:28 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 16:07:51 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int		is_contain_bad(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] > 64 && s[i] < 91)
			i++;
		else if (ft_strchr(SIGN, s[i]) != NULL)
			i++;
		else if (s[i] == '!' || s[i] == ' ' || s[i] == ')' || s[i] == '(')
			i++;
		else if (s[i] == '<' || s[i] == '=' || s[i] == '>')
			i++;
		else
			return (TRUE);
	}
	return (FALSE);
}

static int		is_logic_good(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] > 64 && s[i] < 91 && s[i + 1] != '\0' && s[i + 1] != ' ' && \
				s[i + 1] != ')')
			return (FALSE);
		if (s[i] > 64 && s[i] < 91 && s[i + 1] != '\0' && s[i + 1] != ')' \
				&& ft_strchr(SIGN, s[i + 2]) == NULL && s[i + 2] != '<' \
				&& s[i + 2] != '=')
			return (FALSE);
		if (s[i] == '!' && (s[i + 1] <= 64 || s[i + 1] >= 91))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int		is_sign_good(char *s)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (ft_strchr(SIGN, s[i]) != NULL && s[i + 1] == '\0')
			return (FALSE);
		else if (ft_strchr(SIGN, s[i]) != NULL && s[i + 1] != ' ')
			return (FALSE);
		else if (ft_strchr(SIGN, s[i]) != NULL && s[i + 2] != '!' && \
				(s[i + 2] <= 64 || s[i + 2] >= 91) && s[i + 2] != '(')
			return (FALSE);
	}
	return (TRUE);
}

static int		is_implies_good(char *s)
{
	int		i;

	if (ft_strstr(s, "<=>") == NULL && ft_strstr(s, "=>") == NULL)
		return (FALSE);
	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '>' && s[i + 1] == '\0')
			return (FALSE);
		if (s[i] == '>' && s[i + 1] != ' ')
			return (FALSE);
		if (s[i] == '>' && ft_strchr(LOGICS, s[i + 2]) == NULL && \
				s[i + 2] != '!' && s[i + 2] != '(')
			return (FALSE);
	}
	return (TRUE);
}

int				is_valid_rule(char *rule)
{
	if (is_contain_bad(rule) == TRUE)
		return (FALSE);
	if (is_logic_good(rule) == FALSE)
		return (FALSE);
	if (is_sign_good(rule) == FALSE)
		return (FALSE);
	if (is_implies_good(rule) == FALSE)
		return (FALSE);
	if (is_bracket_good(rule) == FALSE)
		return (FALSE);
	return (TRUE);
}
