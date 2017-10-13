/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_for.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:43:40 by rojones           #+#    #+#             */
/*   Updated: 2016/10/15 10:20:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

static int	ft_check_rule(char *conclusion, char fact)
{
	int	i;

	i = -1;
	while (conclusion[++i] != '\0')
	{
		if (conclusion[i] == fact)
			return (i);
	}
	return (-1);
}

static int	solving_term(char *condition, int *solving)
{
	int	i;
	
	i = 0;
	while (condition[i] != '\0')
	{
		if (isupper(condition[i]) && solving[condition[i] - 'A'] == 1)
			return (1);
		i++;
	}
	return (0);
}

void		ft_run_check(int *solving, t_solve *sv, char fact)
{
	int	re;

	re = ft_eval_cond(strdup(g_rules[sv->i].condition), solving);
	if ((re == 1 && g_infer == 0) || g_infer == 1)
	{
		if (strchr(g_rules[sv->i].conclusion, '|') ||
				strchr(g_rules[sv->i].conclusion, '^'))
		{
			printf(OR_WARNING);
			re = -2;
		}
		if (sv->pos != 0 && re != -2)
			if (g_rules[sv->i].conclusion[sv->pos - 1] == '!')
				re = ft_negate(re);
		printf(RULE_USED);
		if (sv->final == -1)
			sv->final = re;
		else if (re != sv->final && re != -2 && sv->final != -2)
			printf(CONTRADIC_WARNING);
		else if (re != -2)
			sv->final = re;
	}
	else
		printf(CONDITION_NOT_MET);
}

int			ft_find_solution(char fact, int *solving)
{
	t_solve sv;

	sv.i = 0;
	sv.final = -1;
	solving[fact - 'A'] = 1;
	while (sv.i < g_num_rules)
	{
		if (solving_term(g_rules[sv.i].condition, solving) == 0 && (sv.pos =
					ft_check_rule(g_rules[sv.i].conclusion, fact)) != -1)
			ft_run_check(solving, &sv, fact);
		sv.i++;
	}
	solving[fact - 'A'] = 0;
	if (sv.final == -1)
	{
		printf("Solving %c from default value %d\n",
				fact, g_default[fact - 65]);
		return (g_default[fact - 65]);
	}
	else
	{
		printf("Collective result of %c : %d\n", fact, sv.final);
		g_facts[fact - 'A'] = sv.final;
		return (sv.final);
	}
}

int			ft_solve_for(char fact, int *solving)
{
	if (g_short == 0 || (g_facts[fact -'A'] == -1 && g_short == 1))
	{
		return (ft_find_solution(fact, solving));
	}
	else
	{
		printf("\x1B[33mUsing previous result of %c: %d\n\x1B[0m",
			   	fact, g_facts[fact - 'A']);
		return (g_facts[fact - 'A']);
	}
}
