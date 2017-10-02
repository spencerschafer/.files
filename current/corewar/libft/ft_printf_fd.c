/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 09:26:02 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/08/28 09:31:02 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static void		handle_char_fd(int fd, va_list ap, char c)
{
	char		*str;
	int			i;
	char		chr;

	if (c == 's')
	{
		str = va_arg(ap, char *);
		ft_putstr_fd(str, fd);
	}
	else if (c == 'd' || c == 'i')
	{
		i = va_arg(ap, int);
		ft_putnbr_fd(i, fd);
	}
	else if (c == 'c')
	{
		chr = va_arg(ap, int);
		ft_putchar_fd(chr, fd);
	}
	else if (c == '%')
		ft_putchar_fd('%', fd);
	else
		ft_putstr("Conversion not supported (yet)\n");
}

static void		check_char_fd(int fd, const char *restrict format, va_list ap)
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
				handle_char_fd(fd, ap, *format);
			}
			else
				ft_putstr("Conversion not supported (yet)\n");
		}
		else
			ft_putchar_fd(*format, fd);
		if (*format)
			format++;
	}
}

int				ft_printf_fd(int fd, const char *restrict format, ...)
{
	va_list		ap;
	int			ctr;

	ctr = 0;
	if (format)
	{
		va_start(ap, format);
		check_char_fd(fd, format, ap);
		va_end(ap);
		ctr++;
	}
	return (ctr);
}
