/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rhs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 08:16:15 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:24:53 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	is_or(char *str, char logic)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '|' && (str[i - 2] == logic || str[i + 2] == logic))
			return (TRUE);
	}
	return (FALSE);
}

static int	rhs_xor(char *str, char logic, int result, char *skip)
{
	int		i;
	int		val;

	i = -1;
	val = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '^' && str[i - 2] == logic)
			val = get_logic_value(str[i + 2], skip);
		else if (str[i] == '^' && str[i + 2] == logic)
			val = get_logic_value(str[i - 2], skip);
	}
	if (result == FALSE && (val == TRUE || val == FALSE))
		return (val);
	if (result == TRUE && (val == TRUE || val == FALSE))
		return (not_operation(val));
	return (UNDETERMINED);
}

static int	is_xor(char *str, char logic)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '^' && (str[i - 2] == logic || str[i + 2] == logic))
			return (TRUE);
	}
	return (FALSE);
}

int			solve_rhs(char *conclusion, char logic, t_log *log, char *skip)
{
	if (sign_search(conclusion, SIGN) == FALSE)
		return (log->value);
	if (is_or(conclusion, logic) == TRUE)
		return (UNDETERMINED);
	if (is_xor(conclusion, logic) == TRUE)
		return (rhs_xor(conclusion, logic, log->result, skip));
	return (log->value);
}
