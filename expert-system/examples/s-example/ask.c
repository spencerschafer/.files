/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 08:06:59 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/15 11:19:58 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "system.h"

int		ask(void)
{
	char	line[256];
	int		ret;

	printf(KBLUE "Ask :" RESET "\n");
	while (1)
	{
		bzero(line, 256);
		ret = read(0, line, 255);
		line[ret - 1] = '\0';
		if (ret > 0)
		{
			if (ft_strcmp(line, "exit") == 0)
				break ;
			if (ft_strlen(line) > 0)
				question_bank(line);
			printf(KBLUE "Ask :" RESET "\n");
		}
	}
	return (0);
}

int		question_bank(char *ask)
{
	int		ret;

	ret = -1;
	if (ft_strncmp(ask, "why", 3) == 0)
		ret = why_question(ask);
	else if (ft_strncmp(ask, "what", 4) == 0)
		ret = what_question(ask);
	else if (ft_strncmp(ask, "add fact", 8) == 0)
		ret = fact_statement(ask, SET);
	else if (ft_strncmp(ask, "remove fact", 8) == 0)
		ret = fact_statement(ask, UNSET);
	else if (ft_strncmp(ask, "add rule", 8) == 0)
		ret = user_add_rule(ask);
	else if (ft_strncmp(ask, "remove rule", 11) == 0)
		ret = user_remove_rule(ask);
	else if (ft_strcmp(ask, "list rules") == 0)
		ret = user_list_rule();
	if (ret == -1)
		printf(KRED "\tI don't know!" RESET "\n");
	return (0);
}
