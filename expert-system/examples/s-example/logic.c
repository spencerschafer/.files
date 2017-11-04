/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 10:26:31 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:21:55 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	set_value(t_log *log, int count, char logic, int value)
{
	while (count--)
	{
		if (log[count].value == value)
			break ;
	}
	k_base(ADD, logic, value, ink_print_out(&log[count], logic));
	return (value);
}

static int	check_conflicts(t_log *log, int count, char logic, int false_count)
{
	int		i;
	int		true_count;

	i = -1;
	true_count = 0;
	while (++i < count)
	{
		if (log[i].value == TRUE)
			true_count++;
		else if (log[i].value == FALSE)
			false_count++;
	}
	if (true_count > false_count)
		return (set_value(log, count, logic, TRUE));
	else if (false_count > true_count)
		return (set_value(log, count, logic, FALSE));
	else if (true_count > 0 && false_count == true_count)
		return (set_value(log, count, logic, TRUE));
	return (set_value(log, count, logic, UNDETERMINED));
}

int			get_logic_value(char logic, char *skip)
{
	t_kb	*tmp;
	t_log	log[255];
	int		count;
	int		i;

	tmp = k_base(GET, logic, 0, NULL);
	if (tmp != NULL && (tmp->value == TRUE || tmp->value == FALSE))
		return (tmp->value);
	i = ft_strlen(skip);
	skip[i] = logic;
	count = get_logic_value2(&log[0], logic, skip);
	skip[i] = '\0';
	if (count == 0)
	{
		k_base(ADD, logic, FALSE, str_undef(logic));
		return (FALSE);
	}
	return (check_conflicts(&log[0], count, logic, 0));
}
