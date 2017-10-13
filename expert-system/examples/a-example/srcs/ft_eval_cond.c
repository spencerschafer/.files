/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_cond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:17:21 by rojones           #+#    #+#             */
/*   Updated: 2016/10/14 14:33:36 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

void	ft_run_opp(char *condition, t_eval *eval){
	if (eval->neg1)
		eval->t1 = ft_negate(eval->t1);
	if (eval->neg2)
		eval->t2 = ft_negate(eval->t2);
	if (eval->t1 == -2 || eval->t2 == -2)
		eval->op = -2;
	else if (condition[1 + eval->neg1] == '+')
		eval->op = ft_and(eval->t1, eval->t2);
	else if (condition[1 + eval->neg1] == '|')
		eval->op = ft_or(eval->t1, eval->t2);
	else if (condition[1 + eval->neg1] == '^')
		eval->op = ft_xor(eval->t1, eval->t2);
}

void		ft_eval_term(char *condition, int *solving, t_eval *eval)
{
	if (strchr(condition, '(') == NULL)
	{
		eval->neg1 = (condition[0] == '!') ? 1 : 0;
		eval->neg2 = (condition[2 + eval->neg1] == '!') ? 1 : 0;
		eval->t1 =(isalpha(condition[0 + eval->neg1])) ?
			ft_solve_for(condition[0 + eval->neg1], solving) :
			condition[0 + eval->neg1] - '0';
		eval->t2 =(isalpha(condition[2 + eval->neg1 + eval->neg2])) ?
			ft_solve_for(condition[2 + eval->neg1 + eval->neg2], solving) :
			condition[2 + eval->neg1 + eval->neg2] - '0';
		ft_run_opp(condition, eval);
		if (condition[3 + eval->neg1 + eval->neg2] == '\0')
			return ;
		else
		{
			eval->ncon = ft_strnew(1 + (strlen(&condition[3 + eval->neg1 +
							eval->neg2])));
			eval->ncon[0] = '0' + eval->op;
			eval->ncon = strcat(eval->ncon, &condition[3 + eval->neg1 +
					eval->neg2]);
			eval->op = ft_eval_cond(eval->ncon, solving);
		}
	}
	else
		eval->op = ft_eval_brackets(condition, solving);
}

int		ft_eval_cond(char *condition, int *solving)
{
	t_eval eval;

	eval.neg1 = 0;
	eval.neg2 = 0;
	eval.op = -2;
	if (condition[0] != '!' && condition[1] == '\0')
		eval.op = ((isalpha(condition[0])) ? 
				ft_solve_for(condition[0], solving) : condition[0] - '0');
	else if (condition[0] == '!' && condition[2] == '\0')
	{
		eval.op = ((isalpha(condition[1])) ? ft_solve_for(condition[1], solving)
				: condition[1] - '0');
		eval.op = ft_negate(eval.op);
	}
	else
		ft_eval_term(condition, solving, &eval);
	free (condition);
	return eval.op;
}
