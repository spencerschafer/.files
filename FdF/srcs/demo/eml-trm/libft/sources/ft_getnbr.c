/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 11:57:21 by etermeau          #+#    #+#             */
/*   Updated: 2014/12/09 12:29:49 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_getnbr(char *str)
{
	int		tmp;

	tmp = 0;
	if (str != NULL && str[0] == '-')
	{
		return (-ft_getnbr(&str[1]));
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		tmp = (tmp * 10) + (*str - '0');
		str++;
	}
	return (tmp);
}
