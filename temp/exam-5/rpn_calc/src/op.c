#include "rpn.h"
#include <stdlib.h>

int	op(char **stack, int len)
{
	int i;
	int j;
	long a;
	long b;
	long temp;
	long array[len];

	i = 0;
	j = 0;
	clear_longbuf(array, len);
	while (i < len)
	{
		if (!(check_int(atoi(stack[i]))))
			return(0);
		if (ft_strlen(stack[i]) > 1 || (is_number(stack[i][0])))
		{
			array[j] = atoi(stack[i]);
			++j;
		}
		else if (stack[i][0] == '+')
		{
			if ((i - 2) < 0)
				return (0);
			a = array[j - 2];
			b = array[j - 1];
			temp = a + b;
			array[j - 1] = 0;
			array[j - 2] = temp;
			--j;
		}	
		else if (stack[i][0] == '-')
		{
			if ((i - 2) < 0)
				return (0);
			a = array[j - 2];
			b = array[j - 1];
			temp = a - b;
			array[j - 1] = 0;
			array[j - 2] = temp;
			--j;
		}	
		else if (stack[i][0] == '*')
		{
			if ((i - 2) < 0)
				return (0);
			a = array[j - 2];
			b = array[j - 1];
			temp = a * b;
			array[j - 1] = 0;
			array[j - 2] = temp;
			--j;
		}	
		else if (stack[i][0] == '/')
		{
			if ((i - 2) < 0)
				return (0);
			a = array[j - 2];
			b = array[j - 1];
			if (b == 0)
				return (0);
			temp = a / b;
			array[j - 1] = 0;
			array[j - 2] = temp;
			--j;
		}	
		else if (stack[i][0] == '%')
		{
			if ((i - 2) < 0)
				return (0);
			a = array[j - 2];
			b = array[j - 1];
			if (b == 0)
				return (0);
			temp = a % b;
			array[j - 1] = 0;
			array[j - 2] = temp;
			--j;
		}
		++i;	   
	}
	return(array[0]);
}
