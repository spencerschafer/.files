/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   questions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 08:18:53 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:23:30 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		why_question(char *str)
{
	regex_t	regex;
	int		status;

	status = regcomp(&regex, WHY, REG_EXTENDED|REG_NEWLINE);
	if (status != 0)
		return (write(2, REG_COM, ft_strlen(REG_COM)));
	status = regexec(&regex, str, 0, NULL, 0);
	if (status == REG_NOMATCH)
		return (-1);
	answer_why(str);
	return (TRUE);
}

int		what_question(char *str)
{
	regex_t	regex;
	int		status;

	status = regcomp(&regex, WHAT, REG_EXTENDED|REG_NEWLINE);
	if (status != 0)
		return (write(2, REG_COM, ft_strlen(REG_COM)));
	status = regexec(&regex, str, 0, NULL, 0);
	if (status == REG_NOMATCH)
		return (-1);
	answer_what(str);
	return (TRUE);
}

int		fact_statement(char *str, char *reg)
{
	regex_t	regex;
	int		status;

	status = regcomp(&regex, reg, REG_EXTENDED|REG_NEWLINE);
	if (status != 0)
		return (write(2, REG_COM, ft_strlen(REG_COM)));
	status = regexec(&regex, str, 0, NULL, 0);
	if (status == REG_NOMATCH)
		return (-1);
	answer_fact(str);
	return (TRUE);
}

