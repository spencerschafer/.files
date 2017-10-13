/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 12:52:35 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:26:20 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		answer_fact(char *str)
{
	char	logic;
	int		value;

	if (ft_strncmp(str, "add", 3) == 0)
	{
		logic = str[9];
		value = str_value(&str[14]);
		fact_base(ADD, logic, value);
		k_base(SETUP, 'c', 0, NULL);
		printf("\t" KRED "fact added" RESET "\n");
	}
	else if (ft_strncmp(str, "remove", 6) == 0)
	{
		logic = str[12];
		fact_base(ADD, logic, UNKNOWN);
		k_base(SETUP, 'c', 0, NULL);
		printf("\t" KRED "fact removed" RESET "\n");
	}
	return (0);
}
