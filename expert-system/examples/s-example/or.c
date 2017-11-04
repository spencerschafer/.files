/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:24:55 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:23:05 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "system.h"

int		or_operation(int logic1, int logic2)
{
	if (logic1 == TRUE && logic2 == TRUE)
		return (TRUE);
	if (logic1 == TRUE && logic2 == FALSE)
		return (TRUE);
	if (logic1 == FALSE && logic2 == TRUE)
		return (TRUE);
	return (FALSE);
}
