/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reason.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:14:28 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:24:31 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

char	*ink_print_out(t_log *log, char logic)
{
	char	str[100];
	char	s[250];

	bzero(s, 250);
	sprintf(str, "\tFrom Rule\t" KBLUE "%-20s" RESET, log->rule->rule);
	ft_strcat(s, str);
	bzero(str, 100);
	sprintf(str, KMAG "%s" RESET " implies ", log->rule->premise);
	ft_strcat(s, str);
	bzero(str, 100);
	ft_strcat(s, ink_result(log->result));
	sprintf(str, ".....Hence " KBLUE "%c" RESET " is ", logic);
	ft_strcat(s, str);
	ft_strcat(s, ink_value(log->value));
	return (ft_strdup(s));
}

char	*ink_result(int result)
{
	char	str[30];

	if (result == TRUE)
		sprintf(str, KRED "TRUE" RESET);
	else if (result == FALSE)
		sprintf(str, KRED "FALSE" RESET);
	else if (result == UNDETERMINED)
		sprintf(str, KRED "UNDETERMINED" RESET);
	return (ft_strdup(str));
}

char	*ink_value(int value)
{
	char	str[30];

	if (value == TRUE)
		sprintf(str, KRED "TRUE" RESET "\n");
	else if (value == FALSE)
		sprintf(str, KRED "FALSE" RESET "\n");
	else if (value == UNDETERMINED)
		sprintf(str, KRED "UNDETERMINED" RESET "\n");
	return (ft_strdup(str));
}
