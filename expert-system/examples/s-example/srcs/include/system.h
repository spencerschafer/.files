/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:17:38 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 15:55:23 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "libft.h"
# include "struct.h"
# include "defines.h"
# include <regex.h>

/*
*** logic tables
*/
int		and_operation(int logic1, int logic2);
int		or_operation(int logic1, int logic2);
int		xor_operation(int logic1, int logic2);
int		not_operation(int logic);

/*
*** fact base table
*/
int		fact_base(int rule, char logic, int value);
int		add_fact(t_fact *table, int count, char logic, int val);
int		get_fact(t_fact *table, int count, char logic);

/*
*** knowledge base table
*/
t_kb	*k_base(int rule, char logic, int value, char *reason);
t_kb	*get_kb(t_kb *table, char logic);
void	build_knowledge_base(t_kb *table, char *logics);
void	add_kb(t_kb *table, char logic, int value, char *reason);

/*
*** rule base table
*/
t_rule	*rule_base(int rule, t_rule *format_rule, char *unformat_rule);
void	format(char *str, int i, int j);
void	add_rule(t_rule **table, t_rule *rule);

/*
*** tools functions
*/
int		int_write(int fd, char *str);
int		check_not_sign(char *conclusion, char logic);
int		sign_search(char *str, char *find);
int		str_value(char *str);
char	*str_undef(char logic);

/*
*** work memory functions
*/
int		get_logic_value(char logic, char *skip);
int		get_logic_value2(t_log *log, char logic, char *skip);
int		solve_logic(char *str, char *skip, int i);
int		solve_rhs(char *conclusion, char logic, t_log *log, char *skip);

/*
*** interactive functions
*/
int		ask(void);
int		question_bank(char *ask);
int		why_question(char *str);
int		answer_why(char *str);
int		what_question(char *str);
int		answer_what(char *str);
int		fact_statement(char *str, char *reg);
int		answer_fact(char *str);
int		user_add_rule(char *str);
void	ask_samples(void);

/*
*** print out functions
*/
char	*ink_print_out(t_log *log, char logic);
char	*ink_result(int result);
char	*ink_value(int value);
int		logic_puts(char logic);
int		user_remove_rule(char *str);
int		user_list_rule(void);

/*
*** file functions
*/
int		read_file(int fd);
int		is_bracket_good(char *s);
int		is_valid_rule(char *rule);
char	*line_epur(char *str, char *line);

#endif
