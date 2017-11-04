#ifndef RPN_H
#define RPN_H

int		ft_strlen(char *str);
int		ft_stacklen(char **str);
int		is_op(char c);
int		is_number(char c);
int		is_plusminus(char c);
int		is_timesdividemod(char c);
int		create_stack(char **stack, char *str);
int		check_int(long n);
int		op(char **stack, int len);
int		count_op(char **stack, int len);

void	clear_buffer(char *buff, int len);
void	clear_longbuf(long *buff, int len);
void	ft_strcpy(char *dst, char *src);

#endif
