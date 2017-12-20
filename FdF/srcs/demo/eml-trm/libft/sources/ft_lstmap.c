/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 17:54:14 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/18 16:53:10 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list *tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	if (list && f)
	{
		while (list)
		{
			tmp = f(list);
			list = list->next;
		}
	}
	return (tmp);
}
