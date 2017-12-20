/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:02:36 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/09 17:47:09 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while (str[i] >= 127 || str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		nbr *= 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr * neg);
}
