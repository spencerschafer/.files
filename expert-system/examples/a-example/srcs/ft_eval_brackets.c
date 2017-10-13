/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_brackets.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:15:00 by rojones           #+#    #+#             */
/*   Updated: 2016/10/14 14:46:15 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

static int	ft_bracket_length(int start, char *condition)
{
	int	i;
	int	skip;

	i = 1;
	skip = 0;
	while (condition[start + i] != '\0')
	{
		if (condition[start + i] == '(')
			skip++;
		if (condition[start + i] == ')' && skip == 0)
			return (i);
		else if (condition[start + i] == ')')
			skip--;
		i++;
	}
	return (i);
}

int			ft_eval_brackets(char *condition, int *solving)
{
	t_eval_brack ev;

	ev.st = (long)(strchr(condition, '(')) - (long)(condition);
	ev.end = ev.st + ft_bracket_length(ev.st, condition);
	ev.left = ft_strnew(ev.st);
	ev.right = ft_strnew(strlen(condition) - ev.end);
	ev.temp = ft_strnew(ev.end - ev.st - 1);
	ev.left = memcpy(ev.left, condition, ev.st);
	ev.temp = memcpy(ev.temp, &condition[ev.st + 1], ev.end - ev.st - 1);
	ev.right = memcpy(ev.right, &condition[ev.end + 1], strlen(condition) -
			ev.end);
	ev.brace = ft_eval_cond(ev.temp, solving);
	ev.temp = ft_strnew(strlen(ev.left) + strlen(ev.right) + 1);
	ev.temp = memcpy(ev.temp, ev.left, strlen(ev.left));
	ev.temp[strlen(ev.left)] = ev.brace + '0';
	ev.temp = strcat(ev.temp, ev.right);
	free(ev.left);
	free(ev.right);
	return (ft_eval_cond(ev.temp, solving));
}
