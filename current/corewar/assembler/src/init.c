/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:19:05 by hstander          #+#    #+#             */
/*   Updated: 2017/08/21 15:21:25 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** initiates strings to compare op's with.
*/

void	ft_initstr(t_args *ag)
{
	ag->f_str[0] = ft_strdup("lfork");
	ag->f_str[1] = ft_strdup("sti");
	ag->f_str[2] = ft_strdup("fork");
	ag->f_str[3] = ft_strdup("lld");
	ag->f_str[4] = ft_strdup("ld");
	ag->f_str[5] = ft_strdup("add");
	ag->f_str[6] = ft_strdup("zjmp");
	ag->f_str[7] = ft_strdup("sub");
	ag->f_str[8] = ft_strdup("ldi");
	ag->f_str[9] = ft_strdup("or");
	ag->f_str[10] = ft_strdup("st");
	ag->f_str[11] = ft_strdup("aff");
	ag->f_str[12] = ft_strdup("live");
	ag->f_str[13] = ft_strdup("xor");
	ag->f_str[14] = ft_strdup("lldi");
	ag->f_str[15] = ft_strdup("and");
}

/*
** initiates the function pointer array to call function based on the
** corresponding op string.
*/

void	ft_init(t_args *ag)
{
	ag->f_str = (char **)ft_memalloc(sizeof(char *) * 17);
	ag->func[0] = &ft_lfork;
	ag->func[1] = &ft_sti;
	ag->func[2] = &ft_fork;
	ag->func[3] = &ft_lld;
	ag->func[4] = &ft_ld;
	ag->func[5] = &ft_add;
	ag->func[6] = &ft_zjmp;
	ag->func[7] = &ft_sub;
	ag->func[8] = &ft_ldi;
	ag->func[9] = &ft_or;
	ag->func[10] = &ft_st;
	ag->func[11] = &ft_aff;
	ag->func[12] = &ft_live;
	ag->func[13] = &ft_xor;
	ag->func[14] = &ft_lldi;
	ag->func[15] = &ft_and;
	ft_initstr(ag);
}
