/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 08:34:21 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/07/08 13:36:15 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static void		handle_char(va_list ap, char c)
{
	char		*str;
	int			i;
	char		chr;

	if (c == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr(str);
	}
	else if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
	}
	else if (c == 'c')
	{
		chr = va_arg(ap, int);
		ft_putchar(chr);
	}
	else if (c == '%')
		ft_putchar('%');
	else
		ft_putstr("Conversion not supported (yet)\n");
}

static void		check_char(const char *restrict format, va_list ap)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%');
			else if (*format == 's' || *format == 'd' || *format == 'i'
					|| *format == 'c' || *format == 'u' || *format == 'S'
					|| *format == 'p' || *format == 'D' || *format == 'o'
					|| *format == 'U' || *format == 'x' || *format == 'X'
					|| *format == 'C')
			{
				handle_char(ap, *format);
			}
			else
				ft_putstr("Conversion not supported (yet)\n");
		}
		else
			ft_putchar(*format);
		if (*format)
			format++;
	}
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			ctr;

	ctr = 0;
	if (format)
	{
		va_start(ap, format);
		check_char(format, ap);
		va_end(ap);
		ctr++;
	}
	return (ctr);
}
