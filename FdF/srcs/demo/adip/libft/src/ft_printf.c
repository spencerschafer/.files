/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:38:11 by adippena          #+#    #+#             */
/*   Updated: 2016/06/05 16:46:08 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

static char	*my_recognise_arg(char c, va_list ap)
{
	if (c == 's')
		return (va_arg(ap, char *));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	if (c == 'o')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 8));
	if (c == 'x')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 16));
	if (c == 'X')
		return (ft_strtoupper(ft_uitoa_base(va_arg(ap, unsigned int), 16)));
	if (c == 'c')
		return (my_char_to_str(va_arg(ap, int)));
	if (c == 'p')
		return (ft_strjoin("0x", ft_uitoa_base(
			(uintptr_t)va_arg(ap, void*), 16)));
		return (NULL);
}

static char	*my_get_next_percent(const char *str, size_t *offset)
{
	size_t	len;
	size_t	pos;

	len = 0;
	pos = *offset;
	while (str[*offset] != '%' && str[*offset] != '\0')
	{
		*offset += 1;
		len++;
	}
	return (ft_strsub(str, pos, len));
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	char	*out;
	char	*temp;
	size_t	offset;

	va_start(ap, format);
	offset = 0;
	out = ft_strnew(1);
	while (format[offset] != '\0')
		if (format[offset] != '%')
			out = ft_strjoin(out, my_get_next_percent(format, &offset));
		else
		{
			temp = my_recognise_arg(format[offset + 1], ap);
			out = ft_strjoin(out, temp);
			offset += 2;
		}
	ft_putstr(out);
	return (ft_strlen(out));
}
