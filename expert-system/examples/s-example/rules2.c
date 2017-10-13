/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 09:18:33 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:25:37 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	is_rule_exist(char *rule)
{
	t_rule *tmp;

	if ((tmp = rule_base(GET, NULL, NULL)) == NULL)
		return (FALSE);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->rule, rule) == 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int		user_add_rule(char *str)
{
	char	*rule;

	rule = NULL;
	rule = line_epur(&str[9], rule);
	if (is_valid_rule(rule) == FALSE)
		return (printf(KRED "\tInvalid rule: " KBLUE "%s\n", rule));
	if (is_rule_exist(rule) == TRUE)
		return (printf(KRED "\tRule already exists\n" RESET));
	rule_base(SETUP, NULL, rule);
	printf(KRED "\tRule added\n" RESET);
	k_base(SETUP, 'c', 0, NULL);
	return (TRUE);
}


int		user_remove_rule(char *str)
{
	char	*rule;

	rule = NULL;
	rule = line_epur(&str[12], rule);
	if (is_valid_rule(rule) == FALSE)
		return (printf(KRED "\tInvalid rule: " KBLUE "%s\n", rule));
	if (is_rule_exist(rule) == FALSE)
		return (printf(KRED "\tRule does not exist\n" RESET));
	rule_base(REMOVE, NULL, rule);
	printf(KRED "\tRule removed\n" RESET);
	k_base(SETUP, 'c', 0, NULL);
	return (TRUE);
}

int		user_list_rule(void)
{
	t_rule	*rule;

	rule = rule_base(GET, NULL, NULL);
	while (rule != NULL)
	{
		if (rule->bi == FALSE)
			printf(KRED "\t%s\n" RESET, rule->rule);
		rule = rule->next;
	}
	return (TRUE);
}
