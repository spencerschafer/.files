/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 09:49:56 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:23:16 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		logic_puts(char logic)
{
	t_kb	*tmp;

	tmp = k_base(GET, logic, 0, NULL);
	printf("\t" KBLUE "%c" RESET " is ", logic);
	printf("%s", ink_value(tmp->value));
	return (0);
}
