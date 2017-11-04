/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:27:49 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:28:32 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "system.h"

int		xor_operation(int logic1, int logic2)
{
	if (logic1 == TRUE && logic2 == TRUE)
		return (FALSE);
	if (logic1 == TRUE && logic2 == FALSE)
		return (TRUE);
	if (logic1 == FALSE && logic2 == TRUE)
		return (TRUE);
	return (FALSE);
}
