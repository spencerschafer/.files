/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:14:51 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:22:25 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	is_usable_rule(t_rule *rule, char *skip, char logic)
{
	int		i;

	i = -1;
	while (skip[++i] != '\0')
	{
		if (ft_strchr(rule->premise, skip[i]) != NULL)
			return (FALSE);
	}
	if (ft_strchr(rule->conclusion, logic) != NULL)
		return (TRUE);
	return (FALSE);
}

static int	found_rule(t_log *log, int i, t_rule *rule, char *skip)
{
	char	logic;

	logic = skip[ft_strlen(skip) - 1];
	log[i].rule = rule;
	log[i].result = solve_logic(rule->premise, skip, 0);
	log[i].value = log[i].result;
	if (check_not_sign(rule->conclusion, logic) == 1)
		log[i].value = not_operation(log[i].result);
	log[i].value = solve_rhs(rule->conclusion, logic, &log[i], skip);
	if (g_verbose == TRUE)
		printf("%s", ink_print_out(&log[i], logic));
	return (0);
}

int			get_logic_value2(t_log *log, char logic, char *skip)
{
	t_rule	*rules;
	int		count;

	count = 0;
	if ((rules = rule_base(GET, NULL, NULL)) == NULL)
		return (0);
	while (rules != NULL)
	{
		if (is_usable_rule(rules, skip, logic) == TRUE)
		{
			found_rule(log, count, rules, skip);
			count++;
		}
		rules = rules->next;
	}
	return (count);
}
