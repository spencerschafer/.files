/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:55:53 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 10:15:07 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** checks if a line contains a label and calls the correct function for parsing
** the line.
*/

void	ft_lbl_com(t_args *ag)
{
	int		i;
	char	*sub;

	ag->lst = (t_prog *)ft_memalloc(sizeof(t_prog));
	ag->lst->line_no = ag->line_no;
	if ((i = ft_chr_i(ag->trim_str, ':')) > -1)
	{
		if (i > 0 && (ag->trim_str[i + 1] == ' ' ||
					ag->trim_str[i + 1] == '\t' || ag->trim_str[i + 1] == '\0'))
		{
			sub = ft_strsub(ag->trim_str, 0, (i));
			ft_check_lbl(sub, ag); // check 'extras2.c'
			free(sub);
			ft_lbl(ag, i); // see below
		}
		else
			ft_com(ag); // see below
	}
	else
		ft_com(ag); // see below
}

/*
** sets the head of the linked list, and if the head is already set it links the
** next item of the list to the previous.
*/

void	ft_setlist(t_args *ag)
{
	t_prog	*temp;

	temp = ag->head;
	while (temp && temp->next)
		temp = temp->next;
	if (ag->head)
		temp->next = ag->lst;
	else
		ag->head = ag->lst;
}

/*
** gets the commands in the line, and save it in a list item
*/

void	ft_com(t_args *ag)
{
	int		len;
	int		cnt;
	int		k;

	cnt = 0;
	k = 0;
	ag->lst->label = NULL;
	ag->ref = ft_strsplit(ag->trim_str, ',');
	ag->ref2 = ft_split(ag->ref[0], ' ');
	len = ft_arrlen(ag->ref) + ft_arrlen(ag->ref2);
	ag->lst->data = (char **)ft_memalloc(sizeof(char *) * (len));
	while (ag->ref2[cnt])
		ag->lst->data[k++] = ft_strtrim(ag->ref2[cnt++]);
	cnt = 1;
	while (ag->ref[cnt])
		ag->lst->data[k++] = ft_strtrim(ag->ref[cnt++]);
	ag->lst->data[k] = NULL;
	free_2d(&ag->ref);
	free_2d(&ag->ref2);
}

/*
** if the line consists of a label the label and any commands that are on the
** same line is saved into a list item
*/

void	ft_lbl(t_args *ag, int i)
{
	int		cnt;
	int		len;
	int		k;

	cnt = 0;
	k = 0;
	ag->lst->label = ft_strsub(ag->trim_str, 0, (i + 1));
	if (*(ag->trim_str + i + 1) != '\0')
	{
		ag->ref = ft_strsplit(ag->trim_str + i + 1, ',');
		ag->ref2 = ft_split(ag->ref[0], ' ');
		len = ft_arrlen(ag->ref) + ft_arrlen(ag->ref2);
		ag->lst->data = (char **)ft_memalloc(sizeof(char *) * (len));
		while (ag->ref2[cnt])
			ag->lst->data[k++] = ft_strtrim(ag->ref2[cnt++]);
		cnt = 1;
		while (ag->ref[cnt])
			ag->lst->data[k++] = ft_strtrim(ag->ref[cnt++]);
		ag->lst->data[k] = NULL;
		free_2d(&ag->ref);
		free_2d(&ag->ref2);
	}
	else
		ag->lst->data = NULL;
}
