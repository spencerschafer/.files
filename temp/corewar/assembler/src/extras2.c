/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 12:05:41 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 10:40:57 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

int			arg_label(int arg, t_args *ag, t_prog *lst)
{
	char	*sub;
	int		arg_param;

	sub = ft_join(lst->data[arg], 1, (ft_strlen(lst->data[arg]) - 1));
	arg_param = get_label_offset(sub, ag, lst);
	free(sub);
	return (arg_param);
}

char		*ft_join(char *str, int begin, int len)
{
	char	*temp;
	char	*sub;

	temp = ft_strsub(str, begin, len);
	sub = ft_strjoin(temp, ":");
	free(temp);
	return (sub);
}

char		*ft_substr(char *str, int len)
{
	char	*sub;

	sub = ft_strsub(str, 0, len);
	free(str);
	return (sub);
}

void		ft_check_lbl(char *lbl, t_args *ag)
{
	int		i;
	int		j;
	int		flag;
	char	*cmp;

	i = 0;
	flag = 0;
	cmp = LABEL_CHARS;
	while (lbl[i])
	{
		j = 0;
		while (cmp[j])
		{
			if (lbl[i] == cmp[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			my_error(8, ag);
		flag = 0;
		i++;
	}
}
