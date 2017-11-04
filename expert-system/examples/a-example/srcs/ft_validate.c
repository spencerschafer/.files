/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:25:39 by rojones           #+#    #+#             */
/*   Updated: 2016/10/15 10:16:55 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

static int	ft_val_err(int error, char *con, int i)
{
	if (error == 0)
		puts("\x1B[31mERROR: No term defined\x1B[0m");
	if (error == 1)
		puts("\x1B[31mERROR: Extraneous closing brace\x1B[0m");
	if (error == 2)
		puts ("\x1B[31mERROR: Illegal start of expression\x1B[0m");
	if (error == 3)
		printf(M_FACT1 M_FACT2,con ,i);
	if (error == 4)
		puts(M_OPS1 M_OPS2);
	if (error == 5)
		printf(S_UNKNWN, con[i]);
	if (error == 6)
	{
		puts("\x1B[32mSuccessfully validated\x1B[0m");
		return (1);
	}
	return (0);
}

static int	ft_isfactorop(int *op, int *f)
{
	if ((*op == 1 && *f == 0) || (*op == 0 && *f == 0))
	{
		*f = 1;
		*op = 0;
		return (1);
	}
	else if (*f == 1 && *op == 0)
	{
		*f = 0;
		*op = 1;
		return (1);
	}
	else
		return (0);
}

static int	ft_stupid_norme(char *con, t_val *v)
{
	if (con[v->i] == '(')
		v->brace++;
	else if (con[v->i] == ')')
	{
		if (v->brace == 0)
			return (ft_val_err(1, con, v->i));
		else
			v->brace--;
	}
	else if (isupper(con[v->i]))
	{
		if (ft_isfactorop(&v->op, &v->f) == 0)
			return (ft_val_err(3, con, v->i));
	}
	else if (con[v->i] == '+' || con[v->i] == '^' || con[v->i] == '|')
	{
		if (ft_isfactorop(&v->op, &v->f) == 0)
			return (ft_val_err(4, con, v->i));
	}
	else if (con[v->i] != '!')
		return (ft_val_err(5, con, v->i));
	v->i++;
	return (1);
}

static int	ft_validate_str(char *con, int line_no)
{
	t_val	v;

	v.i = 0;
	v.f = 0;
	v.op = 0;
	v.brace = 0;
	printf("\x1B[0mValidating term [ \"%s\" ] on line %d\n", con, line_no);
	if (con[0] == '+' || con[0] == '^' || con[0] == '|')
		return (ft_val_err(2, con, v.i));
	if (con[0] == '\0')
		return (ft_val_err(0, con, v.i));
	while (con[v.i] != '\0')
		if (ft_stupid_norme(con, &v) == 0)
			return (0);
	if (v.op == 0 && v.brace == 0)
		return (ft_val_err(6, con, v.i));
	else
	{
		if (v.op != 0)
			puts(T_OPEN1 T_OPEN2);
		if (v.brace != 0)
			puts("\x1B[31mERROR: Extraneous opening brace\x1B[0m");
		return (0);
	}
}

void		ft_validate_rule(int rulenum, int line_no)
{
	if (ft_validate_str(g_rules[rulenum].condition, line_no) == 0)
	{
		g_rules[rulenum].condition[0] = '\0';
		g_rules[rulenum].conclusion[0] = '\0';
	}
	else if (ft_validate_str(g_rules[rulenum].conclusion, line_no) == 0)
	{
		g_rules[rulenum].condition[0] = '\0';
		g_rules[rulenum].conclusion[0] = '\0';
	}
}
