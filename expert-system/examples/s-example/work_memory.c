/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 08:11:35 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:28:26 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	logic_calculator(int val1, int val2, char sign)
{
	if (val1 == -1)
		return (val2);
	if (sign == '+')
		return (and_operation(val1, val2));
	if (sign == '|')
		return (or_operation(val1, val2));
	if (sign == '^')
		return (xor_operation(val1, val2));
	return (FALSE);
}

static int	solve_brackets(int *val, char *str, int i, char *skip)
{
	int		val2;
	char	sign;

	while (str[i] != '\0' && str[i] != ')')
	{
		if (ft_strchr(SIGN, str[i]) != NULL)
			sign = str[i];
		if (str[i] == '!')
			val2 = not_operation(get_logic_value(str[++i], skip));
		else if (ft_strchr(LOGICS, str[i]) != NULL)
			val2 = get_logic_value(str[i], skip);
		if (val2 != -1)
		{
			*val = logic_calculator(*val, val2, sign);
			val2 = -1;
		}
		i++;
	}
	return (i);
}

int			solve_logic(char *str, char *skip, int i)
{
	int		val1;
	int		val2;
	char	sign;

	val1 = -1;
	val2 = -1;
	while (str[i] != '\0')
	{
		if (ft_strchr(SIGN, str[i]) != NULL)
			sign = str[i];
		if (str[i] == '(')
			i = solve_brackets(&val2, str, i, skip);
		if (str[i] == '!')
			val2 = not_operation(get_logic_value(str[++i], skip));
		else if (ft_strchr(LOGICS, str[i]) != NULL)
			val2 = get_logic_value(str[i], skip);
		if (val2 != -1)
		{
			val1 = logic_calculator(val1, val2, sign);
			val2 = -1;
		}
		i++;
	}
	return (val1);
}
