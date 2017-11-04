/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 09:02:28 by exam              #+#    #+#             */
/*   Updated: 2017/08/23 09:41:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_hex(int c)
{
	char *map = "0123456789abcdef";

	write(1, &map[c / 16], 1);
	write(1, &map[c % 16], 1);
}

unsigned char 	*print_line(unsigned char *mem, size_t size)
{
	unsigned char *mem_c;

	mem_c = mem;
	while ((size_t)(mem_c - mem) < size && (mem_c - mem) < 16)
	{
		print_hex(*mem_c);
		if ((size_t)(mem_c + 1) % 2 == 0)
			write(1, " ", 1);
		++mem_c;
	}
	while((mem_c - mem) < 16)
	{
		write(1, "  ", 2);
		if ((size_t)(mem_c + 1) % 2 == 0)
			write(1, " ", 1);
		++mem_c;
	}
	mem_c = mem;
	while ((size_t)(mem_c - mem) < size && (mem_c - mem) < 16)
	{
		if (*mem_c >= 32 && *mem_c <= 126)
			write(1, &(*mem_c), 1);
		else
			write(1, ".", 1);
		++mem_c;
	}
	write(1, "\n", 1);
	return (mem_c);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *mem;

	mem = (unsigned char *)addr;
	while ((long int)size > 0)
	{
		mem = print_line(mem, size);
		size -= 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
			              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
