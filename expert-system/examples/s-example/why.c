/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   why.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:20:08 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:28:01 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	found_answer(t_kb *tmp, int value, char logic)
{
	if (value != tmp->value)
	{
		printf("No ");
		logic_puts(logic);
	}
	printf("%s", tmp->reason);
	return (0);
}

int			answer_why(char *str)
{
	t_kb	*tmp;
	char	logic;
	int		value;

	logic = str[7];
	value = str_value(&str[9]);
	tmp = k_base(GET, logic, 0, NULL);
	if (tmp != NULL && (tmp->value == TRUE || tmp->value == FALSE || \
				tmp->value == UNDETERMINED))
		return (found_answer(tmp, value, logic));
	printf(KBLUE "%c" RESET " is " KRED "UNDEFINED " RESET, logic);
	printf("....Hence " KBLUE "%c" RESET " is " KRED "FALSE" RESET "\n", logic);
	return (0);
}
