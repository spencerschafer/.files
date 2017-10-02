/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:00:36 by hstander          #+#    #+#             */
/*   Updated: 2017/08/21 15:01:50 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** a call to free all allocated memory.
*/

void	ft_free_all(t_args *ag)
{
	ft_freelst(ag->head);
	free_2d(&ag->f_str);
	free(ag->file_name);
	free(ag->header);
}

/*
** frees the items inside the list.
*/

void	ft_freelst_items(t_prog *lst)
{
	int		i;

	i = 0;
	if (lst->label)
		free(lst->label);
	while (lst->data && lst->data[i])
		free(lst->data[i++]);
	if (lst->data)
		free(lst->data);
}

/*
** frees the linked list.
*/

void	ft_freelst(t_prog *lst)
{
	t_prog	*temp;

	while (lst)
	{
		temp = lst;
		ft_freelst_items(lst);
		lst = lst->next;
		free(temp);
	}
}
