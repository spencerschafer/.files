/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 06:42:36 by sschafer          #+#    #+#             */
/*   Updated: 2017/07/03 09:37:23 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	if (!lst)
		return (NULL);
	head = f(lst);
	if (!head)
		return (NULL);
	new = head;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (!new)
			return (NULL);
		new = new->next;
	}
	return (head);
}

/*
**The trick here is to remember to increment the lst->next, AND to
**increment the link you are applying the reslt of function to.
**i.e increment lst AND new.
**Then finally remember to store the head variable in order to return the
**pointer to the first link
*/
