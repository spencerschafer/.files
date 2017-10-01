/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_offset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:21:05 by hstander          #+#    #+#             */
/*   Updated: 2017/08/28 15:55:35 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** loops through the list to find the offset of the current label, then loops
** then returns the result of the first minus the second.
*/

int		get_label_offset(char *sub, t_args *ag, t_prog *lst)
{
	int		arg_param;
	t_prog	*head;

	head = ag->head;
	arg_param = 0;
	arg_param += lst->bytes;
	while (head)
	{
		if (head->label)
		{
			if (ft_strncmp(head->label, sub, ft_strlen(sub)) == 0)
				break ;
		}
		head = head->next;
	}
	if (head)
	{
		arg_param = (arg_param - head->bytes) * -1;
	}
	else
		my_error(6, ag);
	return (arg_param);
}
