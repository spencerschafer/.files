/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:59:12 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/13 18:42:17 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(int nb)
{
	int		a;

	a = 0;
	while (nb != 0)
	{
		nb = (nb / 10);
		a++;
	}
	return (a);
}

char		*ft_create(void)
{
	char	*new;

	new = malloc(2);
	new[0] = '0';
	new[1] = '\0';
	return (new);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*new;

	len = count(n);
	if (n < 0)
		len++;
	new = malloc(len + 1);
	if (!len)
		return (ft_create());
	if (n < 0)
		new[0] = '-';
	new[len] = '\0';
	while (n)
	{
		if (n < 0)
			new[len - 1] = (n % 10 * -1) + 48;
		else
			new[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (new);
}
