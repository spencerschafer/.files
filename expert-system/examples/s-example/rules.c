/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:11:49 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:25:26 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static void	format_bi(t_rule *tmp)
{
	t_rule	*bi;

	if ((bi = (t_rule *)malloc(sizeof(t_rule))) == NULL)
		exit(printf("Failed to allocate memory\n"));
	bi->bi = TRUE;
	bi->premise = strdup(tmp->conclusion);
	bi->conclusion = strdup(tmp->premise);
	bi->rule = strdup(tmp->rule);
	bi->next = NULL;
	rule_base(ADD, bi, NULL);
}

void		format(char *str, int i, int j)
{
	t_rule	*tmp;

	if ((tmp = (t_rule *)malloc(sizeof(t_rule))) == NULL)
		exit(printf("Failed to allocate memory\n"));
	while (str[i] != '\0' && str[i] != '<' && str[i] != '=')
		i++;
	tmp->premise = ft_strtrim(ft_strsub(str, 0, i));
	j = i;
	while (str[i] != '\0' && (str[i] == '<' || str[i] == '=' || str[i] == '>'))
		i++;
	tmp->conclusion = ft_strtrim(ft_strsub(str, i, ft_strlen(str) - i));
	tmp->rule = strdup(str);
	tmp->bi = FALSE;
	tmp->next = NULL;
	if (g_verbose == TRUE)
		printf(KMAG "%s\n" RESET, str);
	rule_base(ADD, tmp, NULL);
	if (ft_strstr(str, "<=>") != NULL)
		format_bi(tmp);
}

void		add_rule(t_rule **table, t_rule *rule)
{
	if (*table == NULL)
	{
		*table = rule;
		printf(KRED "\tRule added\n" RESET);
	}
	else
	{
		if (ft_strcmp((*table)->premise, rule->conclusion) == 0 && \
			ft_strcmp((*table)->conclusion, rule->premise) == 0 && \
			ft_strcmp((*table)->rule, rule->rule) != 0)
		{
			printf(KBLUE "\t%s" KRED " conflicting rule.\n" RESET, rule->rule);
			printf(KRED "\tRule not added\n" RESET);
			return ;
		}
		add_rule(&(*table)->next, rule);
	}
}

static int	remove_rule(t_rule **table, char *rule)
{
	t_rule *tmp;

	if (*table != NULL)
	{
		if (ft_strcmp((*table)->rule, rule) != 0)
		{
			tmp = *table;
			*table = (*table)->next;
			if (tmp != NULL)
				free(tmp);
		}
		remove_rule(&(*table)->next, rule);
	}
	return (FALSE);
}

t_rule		*rule_base(int rule, t_rule *format_rule, char *unformat_rule)
{
	static t_rule	*table = NULL;

	if (rule == SETUP)
		format(unformat_rule, 0, 0);
	else if (rule == ADD)
		add_rule(&table, format_rule);
	else if (rule == GET)
		return (table);
	else if (rule == REMOVE)
		remove_rule(&table, unformat_rule);
	return (NULL);
}
