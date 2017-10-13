/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 08:16:53 by sasiedu           #+#    #+#             */
/*   Updated: 2016/10/12 14:10:21 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

char	*g_query;
int		g_verbose;

typedef	struct		s_fact
{
	char			logic;
	int				value;
}					t_fact;

/*
*** kb means knowledge base
*/
typedef	struct		s_kb
{
	char			logic;
	int				value;
	char			*reason;
}					t_kb;

typedef	struct		s_rule
{
	int				implies;
	int				bi;
	char			*rule;
	char			*premise;
	char			*conclusion;
	struct s_rule	*next;
}					t_rule;

typedef	struct		s_tree
{
	char			logic[255];
	char			sign[255];
	int				val;
}					t_tree;

typedef	struct		s_log
{
	t_rule			*rule;
	int				result;
	int				value;
}					t_log;

typedef	struct		s_eqn
{
	int				val1;
	int				val2;
	int				i;
	int				val;
	char			sign;
	char			logic;
}					t_eqn;

#endif
