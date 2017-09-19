/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:07:51 by hstander          #+#    #+#             */
/*   Updated: 2017/09/18 16:17:55 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** void		ft_readfile(t_args *ag);
** reads the input file line by line passing each line to the parse line
** function.
*/

void	ft_readfile(t_args *ag)
{
	while (get_next_line(ag->fd, &ag->line) > 0) // see folder 'libft/'
	{
		ag->line_no++; // see 'asm.h'
		parse_line(ag); // see function below
		if (ag->line)
		{
			free(ag->line);
			ag->line = NULL;
		}
	}
	if (ag->line)
	{
		free(ag->line);
		ag->line = NULL;
	}
	close(ag->fd);
}

/*
** void   parse_line(t_args *ag);
** Checks the line read from the file, and creates a linked list based on
** the data.
*/

void	parse_line(t_args *ag)
{
	int		i;

	// removes white space from either side of the string
	ag->trim_str = ft_strtrim(ag->line); // see asm.h && folder 'libft/'

	/*	
	**ft_chr_i searches a string for a char and returns its index if present
	**otherwise it returns -1.
	**ft_substr frees old str and mallocs new string, from start to index.
	**Note: '#' && ';' are considered comments
	*/
	if ((i = ft_chr_i(ag->trim_str, '#')) > -1) // see 'extras.c'
		ag->trim_str = ft_substr(ag->trim_str, i); // see 'extras2.c'
	else if ((i = ft_chr_i(ag->trim_str, ';')) > -1)
		ag->trim_str = ft_substr(ag->trim_str, i); // see 'extras2.c'
	/*
	**
	*/
	if (ag->trim_str[0] == '.')
		ft_nm_com(ag); // see 'name_comment.c"
	else if (ag->trim_str[0])
		ft_lbl_com(ag); // see 'list.c'
	else
	{
		free(ag->trim_str);
		return ;
	}
	ft_setlist(ag); // see 'list.c'
	free(ag->trim_str);
}
