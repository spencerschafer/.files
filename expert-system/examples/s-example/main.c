/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 09:17:38 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:22:47 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

static int	answer_queries(void)
{
	int		i;
	char	*str;

	printf(KMAG "Queries :\n" RESET);
	if (g_query == NULL)
		return (0);
	i = -1;
	str = ft_strnew(255);
	while (g_query[++i] != '\0')
	{
		get_logic_value(g_query[i], str);
		logic_puts(g_query[i]);
	}
	return (0);
}

static int usage(void)
{
	printf(KRED "Error:\n\t" RESET);
	printf(KBLUE "Usage: ./expert_system file " KRED "OR " RESET);
	printf(KBLUE "./expert_sytem -v file\n" RESET);
	return (0);
}

static int	expert_system(char *file)
{
	int		fd;

	if (access(file, F_OK) == -1)
		return (printf(KRED "\tError: file does not exist\n" RESET));
	if (access(file, R_OK) == -1)
		return (printf(KRED "\tError: Access deined\n" RESET));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (printf(KRED "\tError: failed to open file\n" RESET));
	g_query = NULL;
	read_file(fd);
	close(fd);
	k_base(SETUP, 'c', 0, NULL);
	answer_queries();
	ask_samples();
	ask();
	return (0);
}

static int	verbose(char *verbose)
{
	if (ft_strcmp(verbose, "-v") != 0)
		return (FALSE);
	g_verbose = TRUE;
	return (TRUE);
}

int			main(int argc, char **argv)
{
	g_verbose = FALSE;
	if (argc == 3)
	{
		if (verbose(argv[1]) == FALSE)
			return (usage());
	}
	else if (argc != 2)
		return (usage());
	if (argc == 3)
		expert_system(argv[2]);
	else
		expert_system(argv[1]);
	return (0);
}
