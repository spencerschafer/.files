/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:18:17 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:17:18 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		and_operation(int logic1, int logic2)
{
	if (logic1 == TRUE && logic2 == TRUE)
		return (TRUE);
	if (logic1 == TRUE && logic2 == FALSE)
		return (FALSE);
	if (logic1 == FALSE && logic2 == TRUE)
		return (FALSE);
	return (FALSE);
}
