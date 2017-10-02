/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 10:43:59 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:59:25 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** Checks that the last two chars in the file name is '.s'.
*/

int		check_valid_file(t_args *ag, char *file_name)
{
	int		fn_len;
	char	*temp;

	fn_len = ft_strlen(file_name);
	if (file_name[fn_len - 1] != 's' || file_name[fn_len - 2] != '.')
		return (1);
	else
	{
		temp = ft_strsub(file_name, 0, (fn_len - 2));
		ag->file_name = ft_strjoin(temp, ".cor");
		free(temp);
		return (0);
	}
}

/*
** Checks that correct number of arguments received, and that the passed
** argument ends with '.s'.
** If arguments are correct, tries to open the file and return fd
** if successfull.
*/

int		check_arguments(t_args *ag, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_printf_fd(2, "Invalid num of args. Usage: ./asm mychampion.s\n");
		exit(0);
	}
	ft_printf("Assembeling : %s\n", argv[1]);
	if (check_valid_file(ag, argv[1]) != 0)
	{
		ft_printf_fd(2, "Invalid file - file must end with .s extension\n");
		exit(0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error");
		exit(0);
	}
	return (fd);
}
