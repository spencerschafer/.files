/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:01:07 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:21:34 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

/*
*** knowledge base
*/

t_kb	*k_base(int rule, char logic, int value, char *reason)
{
	static t_kb		table[26];

	if (rule == SETUP)
		build_knowledge_base(&table[0], LOGICS);
	else if (rule == GET)
		return (get_kb(&table[0], logic));
	else if (rule == ADD)
		add_kb(&table[0], logic, value, reason);
	return (NULL);
}

void	add_kb(t_kb *table, char logic, int value, char *reason)
{
	int		i;

	i = -1;
	while (++i < 26)
	{
		if (table[i].logic == logic)
		{
			table[i].value = value;
			table[i].reason = ft_strdup(reason);
			return ;
		}
	}
}

void	build_knowledge_base(t_kb *table, char *logics)
{
	int		i;
	char	s1[30];
	char	s2[30];

	i = -1;
	sprintf(s1, KRED "\tIt is Fact" RESET "\n");
	sprintf(s2, KRED "\tIt is Unknown" RESET "\n");
	while (logics[++i] != '\0')
	{
		table[i].logic = logics[i];
		table[i].value = fact_base(GET, logics[i], 0);
		if (table[i].value == UNKNOWN)
			table[i].reason = ft_strdup(s2);
		else
			table[i].reason = ft_strdup(s1);
	}
}

t_kb	*get_kb(t_kb *table, char logic)
{
	t_kb	*tmp;
	int		i;

	i = -1;
	while (++i < 26)
	{
		tmp = &table[i];
		if (tmp->logic == logic)
			return (tmp);
	}
	return (NULL);
}
