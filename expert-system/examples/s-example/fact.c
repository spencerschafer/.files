/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:28:45 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:21:03 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	remove_fact(t_fact *table, int count, char logic)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		if (table[i].logic == logic)
			break ;
	}
	if (i == count)
		return (count);
	while (i < count - 1)
	{
		table[i] = table[i + 1];
		i++;
	}
	count -= 1;
	return (count);
}

int		fact_base(int rule, char logic, int value)
{
	static t_fact	table[26];
	static int		count = 0;

	if (rule == ADD)
		count += add_fact(&table[0], count, logic, value);
	else if (rule == GET)
		return (get_fact(&table[0], count, logic));
	else if (rule == REMOVE)
		count = remove_fact(&table[0], count, logic);
	return (0);
}

int		add_fact(t_fact *table, int count, char logic, int val)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		if (table[i].logic == logic)
		{
			table[i].value = val;
			return (1);
		}
	}
	table[i].logic = logic;
	table[i].value = val;
	return (1);
}

int		get_fact(t_fact *table, int count, char logic)
{
	int		i;

	i = -1;
	while (++i < count)
	{
		if (table[i].logic == logic)
			return (table[i].value);
	}
	return (UNKNOWN);
}
