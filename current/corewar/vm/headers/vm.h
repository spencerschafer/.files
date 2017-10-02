/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:35:37 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/14 09:15:58 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VM_H
# define __VM_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <ncurses.h>
# include "../../libft/libft.h"

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			s_op
{
	char				*name;
	int					no_args;
	char				type[MAX_ARGS_NUMBER];
	char				id;
	int					no_cycles;
	char				*desc;
	int					has_acb;
	int					is_index;
}						t_op;

extern t_op				g_op_tab[];

typedef struct s_header	t_header;
typedef struct s_champ	t_champ;
typedef struct s_vm		t_vm;

struct					s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
};

struct					s_champ
{
	int					player_num;
	t_header			head;
	unsigned char		prog[CHAMP_MAX_SIZE];
	int					alive;
	int					called_alive;
	int					carry;
	int					pc;
	int					reg[17];
	int					exec_cycle;
	struct s_champ		*next;
};

struct					s_vm
{
	unsigned char		mem[MEM_SIZE];
	long long			cur_cycle;
	unsigned int		dump_cycle;
	unsigned int		total_cycles;
	long long			cycle_to_die;
	unsigned int		cycle_delta;
	unsigned int		live_calls;
	unsigned int		checks;
	unsigned int		last_live;
	void				(*func[17])(t_vm *, t_champ *);
};

typedef struct			s_info
{
	int					ac;
	char				**av;
	t_champ				*champ_head;
	t_vm				*vm;
	int					p_num;
}						t_info;

/*
**	check_key_swop_bytes.c
*/

char					*add_byte(unsigned char *mem_c, char *key);
int						check_key(const void *mem, size_t size);

/*
**	open_files.c
*/

void					open_files(t_info *info);
int						get_next_player_number(t_champ *champ_head);
int						check_availible_num(t_champ *champ_head, int nbr);
void					malloc_new_champ(t_info *info, int ctr, t_champ
							**champ_ptr);

/*
**	read_champs.c
*/

void					check_magic(t_champ *champ_ptr, t_info *info);
void					check_file_size(t_champ *champ_ptr, t_info *info);
void					read_champ(int fd, t_champ *champ_ptr, t_info *info);

/*
**	print_mem.c
*/

void					ft_print_hex(int c);
unsigned char			*print_line(unsigned char *mem, size_t size, int bit);
void					print_memory(const void *addr, size_t size, int bit);
int						get_int_from_mem(unsigned char *mem, int size);
void					print_mem_nc(const void *addr, size_t size, int bit);

/*
**	init_vm.c
*/

void					alloc_champ_mem(t_vm *vm, t_champ *champ_ptr,
							int offset);
void					init_vm(t_vm *vm, t_champ *champ_head, int argc);

/*
**	print_champ_mem.c
*/

void					print_vm_nc(t_vm vm, int bit);
void					print_vm(t_vm vm, int bit);
void					print_champ(t_champ *champ_ptr);

/*
**	run_machine_run.c
*/

int						check_who_alive(t_champ *champ_head);
void					new_cycle_to_die(t_champ *champ_head, t_vm *vm);
void					call_live(t_champ *champ_head, t_champ *champ_ptr,
							t_vm *vm);
void					exec_champ(t_champ *champ_head,
							t_champ *champ_ptr, t_vm *vm);
void					run_machine_run(t_champ *champ_head, t_vm *vm);

/*
**	vm_utils.c
*/

void					free_structs(t_champ **head, t_vm **vm);
int						swop_bytes(int i, int no_bytes);
void					print_usage_exit(void);
void					read_main_info(char **argv, t_champ *champ_head,
							t_vm *vm, t_info *info);
void					unable_to_open(t_info *info, int ctr);

/*
**	utils2_vm.c
*/

void					check_dump_cycle(t_champ *champ_head, t_vm *vm);

/*
**	vm_main.c
*/

void					print_usage_flags(int argc, char **argv, int arg_count);
int						count_flags(int argc, char **argv);
void					find_winner_struct(t_champ *champ_head, int ll);
void					reverse_list(t_champ **champ_head);

/*
**	opcodes .c
*/

void					ft_ld(t_vm *vm, t_champ *champ);
void					ft_st(t_vm *vm, t_champ *champ);
void					ft_add(t_vm *vm, t_champ *champ);
void					ft_sub(t_vm *vm, t_champ *champ);
void					ft_and(t_vm *vm, t_champ *champ);
void					ft_or(t_vm *vm, t_champ *champ);
void					ft_xor(t_vm *vm, t_champ *champ);
void					ft_zjmp(t_vm *vm, t_champ *champ);
void					ft_ldi(t_vm *vm, t_champ *champ);
void					ft_sti(t_vm *vm, t_champ *champ);
void					ft_fork(t_vm *vm, t_champ *champ);
void					ft_lld(t_vm *vm, t_champ *champ);
void					ft_lldi(t_vm *vm, t_champ *champ);
void					ft_lfork(t_vm *vm, t_champ *champ);
void					ft_aff(t_vm *vm, t_champ *champ);
void					ft_decode(unsigned int i, unsigned char *buf);
int						to_signed_ind(unsigned char *bytes);
int						to_signed_dir(unsigned char *bytes);
int						mem_check(int pc);
void					init_champ(t_champ *champ, t_champ *new_champ);
int						ft_direct(t_vm *vm, int *c_pc);
int						ft_indirect(t_vm *vm, int *c_pc);
int						ft_reg(t_vm *vm, int *c_pc, t_champ *champ);

#endif
