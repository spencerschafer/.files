/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_system.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:55:21 by rojones           #+#    #+#             */
/*   Updated: 2016/10/15 15:24:25 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_SYSTEM_H
# define EX_SYSTEM_H

# include <libc.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

# define OR_WARNING "\x1B[31mWarning OR type operand in conclusion, result is \
undefined\x1B[0m\n"
# define RULE_USED "Used rule [ \"%s => %s\" ] to solve %c - Result: %d\n"\
, g_rules[sv->i].condition, g_rules[sv->i].conclusion, fact, re
# define CONTRADIC_WARNING "\x1B[31mWarning contradicting results for %c - \
Previous Result: %d, Current Result: %d\x1B[0m\n", fact, sv->final, re
# define CONDITION_NOT_MET "\x1B[33mcondition [%s] %d not met fact[%c] not \
changed\n\x1B[0m", g_rules[sv->i].condition, re, fact
# define M_FACT1 "\x1B[31mERROR: Multiple facts not seperated by an "
# define M_FACT2 "operator %s at index %d\n\x1B[0m"
# define M_OPS1 "\x1B[31mERROR: Multiple operators not seperated "
# define M_OPS2 "by a fact\x1B[0m"
# define T_OPEN1 "\x1B[31mERROR: Condition ends with an open term. Add fact "
# define T_OPEN2 "after the last operator\x1B[0m"
# define S_UNKNWN "\x1B[31mERROR: Symbol[ \'%c\' ] not recognised\n\x1B[0m"
# define CONC "conclusion"
# define COND "condition"
# define NOTE "NOTE:\x1B[32m 1 = TRUE,\x1B[31m 0 = FALSE,\x1B[33m \
-2 = UNDEFINED.\x1B[0m\n"

typedef struct	s_val
{
	int		i;
	int		f;
	int		op;
	int		brace;
}				t_val;

typedef struct	s_file
{
	FILE	*fp;
	int		re;
	char	*line;
	int		line_no;
	size_t	n;
	int		s;
}				t_file;

typedef struct	s_rule
{
	char	*condition;
	char	*conclusion;
}				t_rule;

typedef struct	s_solve
{
	int		i;
	int		pos;
	int		final;
}				t_solve;

typedef struct	s_eval
{
	int     neg1;
	int     neg2;
	int     t1;
	int     t2;
	int     op;
	char    *ncon;
}				t_eval;

typedef struct	s_eval_brack
{
	int		st;
	int		end;
	int		brace;
	char	*left;
	char	*right;
	char	*temp;
}				t_eval_brack;


int		g_num_rules;
int		g_rule_no;
int		g_facts[26];
int		g_default[26];
int		g_short;
int				g_infer;
t_rule	*g_rules;
char	*g_prove;


int				ft_and(int t1, int t2);
void			ft_drop_spaces(char *line);
int				ft_eval_brackets(char *condition, int *solving);
int				ft_eval_cond(char *condition, int *solving);
int				ft_getnum_rules(char *file, t_file *f);
int				ft_negate(int t);
int				ft_or(int t1, int t2);
void			ft_read_file(char *file);
void			ft_read_info(char *file, t_file *f);
int				ft_solve_for(char fact, int *solving);
int				ft_strlen_n(char *st);
int				ft_strlen_rule(char *st);
char			*ft_strnew(size_t size);
void			ft_validate_rule(int rulenum, int line_no);
int				ft_xor(int t1, int t2);
void			get_con(char *line, int i, int rule_no);
void			get_rule(char *line, int i, int *rule_no);
void			init_file_struct(t_file *f);
int				rule_check(t_file *f);
void			read_file_sub(t_file *f);

#endif
