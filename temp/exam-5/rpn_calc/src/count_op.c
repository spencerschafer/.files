#include "rpn.h"

int	count_op(char **stack, int len)
{
	int i;
	int operand;
	int operator;

	i = 0;
	operand = 0;
	operator = 0;
	while (i < len)
	{
		if (is_op(stack[i][0]) && ft_strlen(stack[i]) == 1)
			++operator;
		else
			++operand;
		++i;
	}
	if (operator == (operand - 1))
		return (1);
	return (0);
}
