/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 16:23:56 by sschafer          #+#    #+#             */
/*   Updated: 2017/07/03 06:28:34 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	*alst = new;
	new->next = temp;
}

/*
**...**alst
**		|
**pointerfirstlink - pointerfirstlinkNEXT
**
**store pointerfirstlink in temp variable
**dereference *alst and change it to new
**pointernewNEXT needs to point to temp
*/
