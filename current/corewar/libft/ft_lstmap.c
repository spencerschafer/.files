/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:16:40 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/10 13:50:46 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *ret_start;

	ret_start = f(lst);
	lst = lst->next;
	ret = ret_start;
	while (lst)
	{
		ret->next = f(lst);
		ret = ret->next;
		lst = lst->next;
	}
	ret = NULL;
	return (ret_start);
}
