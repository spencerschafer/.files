#include "rpn.h"
#include <stdlib.h>

int	create_stack(char **stack, char *str)
{
	int i;
	int j;
	int k;
	char temp[11];

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		if (is_plusminus(str[i]))
		{
			temp[j] = str[i];
			++i;
			++j;
			if (is_number(str[i]))
			{
				while (is_number(str[i]))
				{
					temp[j] = str[i];
					++i;
					++j;
				}
			}
			else if (str[i] == ' ')
				++i;
			else if (str[i] != '\0')
				return(0);
			temp[j] = '\0';
			stack[k] = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
			ft_strcpy(stack[k++], temp);
			clear_buffer(temp, ft_strlen(temp));
		}
		else if (is_timesdividemod(str[i]))
		{
			temp[j] = str[i];
			++i;
			++j;
			if (str[i] == ' ')
				++i;
			else if (str[i] != '\0')
				return(0);
			temp[j] = '\0';
			stack[k] = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
			ft_strcpy(stack[k++], temp);
			clear_buffer(temp, ft_strlen(temp));
		}
		else if (is_number(str[i]))
		{
			temp[j] = str[i];
			++i;
			++j;
			if (is_number(str[i]))
			{
				while (is_number(str[i]))
				{
					temp[j] = str[i];
					++i;
					++j;
				}
			}
			else if (str[i] == ' ')
				++i;
			else if (is_op(str[i]))
				return(0);
			else if (str[i] == '\0')
				return(0);
			temp[j] = '\0';
			stack[k] = (char *)malloc(sizeof(char) * (ft_strlen(temp) + 1));
			ft_strcpy(stack[k++], temp);
			clear_buffer(temp, ft_strlen(temp));
		}
		else
		{
			if (str[i] == ' ')
				++i;
			else
				return(0);
		}
	}
	stack[k] = 0;
	return (1);
}
