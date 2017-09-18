/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 10:21:51 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/18 16:23:13 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** writes magic number, program name, program size and program comments to the
** binary file.
*/

void		ft_writename(t_args *ag)
{
	swap_bytes(COREWAR_EXEC_MAGIC, ag->fd);
	write(ag->fd, &ag->header->prog_name, (PROG_NAME_LENGTH + 4));
	swap_bytes(ag->header->prog_size, ag->fd);
	write(ag->fd, &ag->header->comment, (COMMENT_LENGTH + 4));
}

/*
** iterates through the list and calls the relevant function according to the op
*/

void		ft_list_iter(t_args *ag)
{
	t_prog	*lst;
	int		i;

	lst = ag->head;
	i = 0;
	while (lst)
	{
		i = 0;
		ag->lst = lst;
		if (lst->label)
			ag->cur_label = lst->label;
		if (lst->data && lst->data[0])
		{
			while (i < 16)
			{
				if (ft_strcmp(ag->f_str[i], lst->data[0]) == 0)
				{
					ag->func[i](ag, lst);
					break ;
				}
				i++;
			}
		}
		lst = lst->next;
	}
}

int			main(int argc, char **argv)
{
	t_args	ag;
	t_prog	*lst;

	ft_bzero(&ag, sizeof(t_args)); // sets contents of file to '/0' - see folder 'libft/'
	ag.header = (t_header *)ft_memalloc(sizeof(t_header)); // allocating memory to hold a t_header - see 'op.h'
	ag.fd = check_arguments(&ag, argc, argv); // determines whether arguemnts entered are valid - see 'check.c'
	ft_readfile(&ag); // see 'parse_line.c'
	check_nm_com(&ag); // see 'name_comment.c"
	ag.fd = open(ag.file_name, O_WRONLY | O_TRUNC | O_CREAT, 0666); // see '<fcntl.h>'
	ft_init(&ag); // see 'init.c'
	lst = ag.head; // see 'asm.h'
	ag.header->prog_size = label_offset(lst, &ag); // see 'label_offset.c'
	ft_writename(&ag); // see function above
	ft_list_iter(&ag); // see function above
	ft_printf("Name        : %s\n", ag.header->prog_name);
	ft_printf("Comment     : %s\n", ag.header->comment);
	ft_free_all(&ag); // see 'free.c'
	close(ag.fd);
	return (0);
}
