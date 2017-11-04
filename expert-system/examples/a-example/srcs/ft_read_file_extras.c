/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_extras.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:33:06 by arnovan-          #+#    #+#             */
/*   Updated: 2016/10/15 13:27:40 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

int			ft_strlen_n(char *st)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
	while (st[i] != '\0' && st[i] != '#')
	{
		if (isspace(st[i]) == 0)
			re++;
		i++;
	}
	return (re);
}

void		ft_drop_spaces(char *line) 
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	re = line;
	while(line[i] != '\0')
	{
		if (isspace(line[i]))
			i++;
		else
			re[j++] = line[i++];
	}
	re[j] = '\0';
}

int			ft_strlen_rule(char *st)
{
	int	i;
	int	re;

	i = 0;
	re = 0;
	while (st[i] != '\0' && st[i] != '#')
	{
		if (isspace(st[i]) == 0)
			re++;
		i++;
	}
	return (re);
}

int			rule_check(t_file *f)
{
	int i;

	i = 0;
	ft_drop_spaces(f->line);
	if (f->line[i] != '#' && f->line[i] != '=' &&
			f->line[i] != '?' && f->line[i] != '\0')
	{
		char *temp = strstr(f->line, "<=>");
		if (temp)
		{
			if (strchr(f->line, '#') == NULL)
				f->re++;
			else if ((long int)temp < (long int)(strchr(f->line, '#')))
				f->re++;
		}
		f->re++;
	}
	(f->line[i] == '=' && f->line[i + 1] == '>') ? f->re++ : 0;
	return (f->re);
}

void		read_file_sub(t_file *f)
{
	int	i;

	i = 0;
	*(strrchr(f->line,'\n'))='\0';
	ft_drop_spaces(f->line);
	if (f->line[i] != '#' && f->line[i] != '\0')
	{
		if (f->line[i] == '=' && f->line[i + 1] != '>')
		{
			while (isupper(f->line[++i]))
				g_default[(f->line[i] - 'A')] = 1;
		}
		else if (f->line[i] == '?')
		{
			g_prove = (char*)(malloc(ft_strlen_n(&f->line[i++])));
			while(f->line[i] != '\0' && f->line[i] != '#')
				if (isupper(f->line[i++]))
					g_prove[f->s++]=f->line[i - 1];
			g_prove[f->s]='\0';
		}
		else
		{
			get_rule(f->line, i, &g_rule_no);
			ft_validate_rule(g_rule_no++, f->line_no);
		}
	}
	f->line_no++;
}
