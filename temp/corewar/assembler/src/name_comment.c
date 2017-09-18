/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:13:23 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 12:49:13 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** saves the name of the program to the header struct if it passes all the
** tests.
*/

void	ft_name(t_args *ag, int i)
{
	int		j;
	char	*temp;

	if ((j = ft_chrn_i(ag->trim_str, '"')) > i)
	{
		if (ag->trim_str[j + 1] != '\0')
			my_error(8, ag);
		temp = ft_strsub(ag->trim_str, (i + 1), (j - i - 1));
		if (ft_strlen(temp) > PROG_NAME_LENGTH)
		{
			ft_printf_fd(2, "Name to big:\n%s\n", ag->trim_str);
			free(temp);
			exit(6);
		}
		ft_strcpy(ag->header->prog_name, temp);
		ag->name_f = 1;
		free(temp);
	}
	else
		my_error(5, ag);
}

/*
** saves the comment of the program to the header struct if it passes all the
** tests.
*/

void	ft_comment(t_args *ag, int i)
{
	int		j;
	char	*temp;

	if ((j = ft_chrn_i(ag->trim_str, '"')) > i)
	{
		if (ag->trim_str[j + 1] != '\0')
			my_error(8, ag);
		temp = ft_strsub(ag->trim_str, (i + 1), (j - i - 1));
		if (ft_strlen(temp) > COMMENT_LENGTH)
		{
			ft_printf_fd(2, "comment to big:\n%s\n", ag->trim_str);
			free(temp);
			exit(6);
		}
		ft_strcpy(ag->header->comment, temp);
		ag->comment_f = 1;
		free(temp);
	}
	else
		my_error(5, ag);
}

/*
** prints a error message depending on the input integer.
*/

int		ft_exit_nmcm(t_args *ag, int i)
{
	if (i == -1)
		ft_printf_fd(2, "Invalid name:\n%s\n", ag->trim_str);
	if (i == -2)
		ft_printf_fd(2, "Invalid comment:\n%s\n", ag->trim_str);
	if (i == -3)
		ft_printf_fd(2, "Invalid command %s\n", ag->trim_str);
	return (i);
}

/*
** if a line starts with a '.' it checks if the line is the program name or the
** program comments, and calls the relevant function to save the name or
** comment into the header struct.
*/

void	ft_nm_com(t_args *ag)
{
	int		i;

	if (ft_strncmp(ag->trim_str, ".name", 5) == 0)
	{
		if ((i = ft_chr_i(ag->trim_str, '"')) > -1)
			ft_name(ag, i);
		else
			exit(ft_exit_nmcm(ag, -1));
	}
	else if (ft_strncmp(ag->trim_str, ".comment", 8) == 0)
	{
		if ((i = ft_chr_i(ag->trim_str, '"')) > -1)
			ft_comment(ag, i);
		else
			exit(ft_exit_nmcm(ag, -2));
	}
	else
		exit(ft_exit_nmcm(ag, -3));
}

void	check_nm_com(t_args *ag)
{
	if (ag->name_f == 0)
	{
		ft_printf_fd(2, "No name present\nAborting ...\n");
		exit(-1);
	}
	if (ag->comment_f == 0)
	{
		ft_printf_fd(2, "No comment present\nAborting ...\n");
		exit(-1);
	}
}
