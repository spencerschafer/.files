/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:05:24 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/29 11:14:37 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int ctr;
	int src_ctr;

	ctr = 0;
	src_ctr = 0;
	while (dest[ctr])
	{
		ctr++;
	}
	while (src[src_ctr])
	{
		dest[ctr] = src[src_ctr];
		ctr++;
		src_ctr++;
	}
	dest[ctr] = '\0';
	return (dest);
}
