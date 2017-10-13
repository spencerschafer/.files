/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:02:29 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/12 08:54:24 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		answer_what(char *str)
{
	char	logic;

	logic = str[21];
	get_logic_value(logic, NULL);
	logic_puts(logic);
	return (0);
}
