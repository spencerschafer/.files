/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 12:44:26 by sschafer          #+#    #+#             */
/*   Updated: 2017/07/03 11:35:02 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

/*
**pass pointer
**frees pointer content using function del
**frees pointer memory using free
**next must remain unfreed and pointer remains the same
**set pass pointer to NULL
**...
**In detail: A link generally mallocs memory twice. 1 for the actual content
**and 2 for the pointer itself. Both of these need to freed.
**pointer -> pointer -> *content & content_size
*/
