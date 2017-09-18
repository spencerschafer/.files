/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 10:59:32 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/14 12:49:34 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ASM_H
# define __ASM_H

# include "../../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "op.h"

typedef struct s_prog	t_prog;
typedef struct s_args	t_args;
typedef struct s_size	t_size;

struct					s_prog
{
	char				*label;
	char				**data;
	int					bytes;
	int					line_no;
	t_prog				*next;
};

struct					s_args
{
	void				(*func[17])(t_args *, t_prog *);
	t_prog				*head;
	t_prog				*lst;
	t_header			*header;
	char				*cur_label;
	char				*file_name;
	char				**f_str;
	char				*line;
	int					line_no;
	char				*trim_str;
	char				**ref;
	char				**ref2;
	int					fd;
	int					name_f;
	int					comment_f;
};

int						check_arguments(t_args *ag, int argc, char **argv);
int						check_valid_file(t_args *ag, char *file_name);
void					parse_line(t_args *ag);
void					ft_readfile(t_args *ag);
void					ft_setlist(t_args *ag);
void					ft_lbl_com(t_args *ag);
void					ft_com(t_args *ag);
void					ft_lbl(t_args *ag, int i);
void					ft_nm_com(t_args *ag);
int						ft_chr_i(char *str, char c);
int						ft_chrn_i(char *str, char c);
void					swap_bytes(unsigned int i, int fd);
size_t					ft_arrlen(char **arr);
void					ft_lfork(t_args *ag, t_prog *lst);
void					ft_sti(t_args *ag, t_prog *lst);
void					ft_fork(t_args *ag, t_prog *lst);
void					ft_lld(t_args *ag, t_prog *lst);
void					ft_ld(t_args *ag, t_prog *lst);
void					ft_add(t_args *ag, t_prog *lst);
void					ft_zjmp(t_args *ag, t_prog *lst);
void					ft_sub(t_args *ag, t_prog *lst);
void					ft_ldi(t_args *ag, t_prog *lst);
void					ft_or(t_args *ag, t_prog *lst);
void					ft_st(t_args *ag, t_prog *lst);
void					ft_aff(t_args *ag, t_prog *lst);
void					ft_live(t_args *ag, t_prog *lst);
void					ft_xor(t_args *ag, t_prog *lst);
void					ft_lldi(t_args *ag, t_prog *lst);
void					ft_and(t_args *ag, t_prog *lst);
int						label_offset(t_prog *lst, t_args *ag);
void					ft_free_all(t_args *ag);
void					ft_freelst(t_prog *lst);
void					ft_freelst_items(t_prog *lst);
void					ft_initstr(t_args *ag);
void					ft_init(t_args *ag);
int						get_label_offset(char *sub, t_args *ag, t_prog *lst);
int						ft_checknum(char *sub, t_args *ag);
void					my_error(int error, t_args *ag);
void					delete_cor(int error, t_args *ag);
char					*ft_join(char *str, int begin, int len);
int						arg_label(int arg, t_args *ag, t_prog *lst);
char					*ft_substr(char *str, int len);
void					ft_check_lbl(char *lbl, t_args *ag);
void					check_nm_com(t_args *ag);

#endif
