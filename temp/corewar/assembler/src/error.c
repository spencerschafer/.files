/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:14:58 by hstander          #+#    #+#             */
/*   Updated: 2017/08/28 17:22:04 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

void	delete_cor(int error, t_args *ag)
{
	remove(ag->file_name);
	ft_printf_fd(2, "Aborting...\n");
	exit(error);
}

void	my_error(int error, t_args *ag)
{
	if (error == 1)
		ft_printf_fd(2, "Error on line #%d - Invalid register\n",
			ag->lst->line_no);
	if (error == 2)
		ft_printf("Error on line #%d - Invalid argument\n", ag->lst->line_no);
	if (error == 3)
		ft_printf_fd(2, "Unable to write to file\n");
	if (error == 4)
		ft_printf_fd(2, "Error on line #%d - Incorrect amount of arguements\n",
			ag->lst->line_no);
	if (error == 5)
		ft_printf_fd(2, "Non terminated string:\n%s\n", ag->trim_str);
	if (error == 6)
		ft_printf_fd(2, "Error on line #%d - Invalid Label\n",
			ag->lst->line_no);
	if (error == 7)
		ft_printf_fd(2, "Error on line #%d - Invalid op code\n",
			ag->lst->line_no);
	if (error == 8)
		ft_printf_fd(2, "Syntax error:\n%s\n", ag->trim_str);
	delete_cor(error, ag);
}
