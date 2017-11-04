#include "rpn.h"

int	ft_stacklen(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		++i;
	return (i);
}
