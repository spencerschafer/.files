#include "rpn.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int str_len;
		int stack_len;
		int ret;
		char **stack;

		str_len = ft_strlen(argv[1]);
		stack = (char **)malloc(sizeof(char *) * (str_len + 1));
		ret = create_stack(stack, argv[1]);
		stack_len = ft_stacklen(stack);
		if (!ret || !count_op(stack, stack_len))
			printf("Error\n");
		else
		{
			ret = op(stack, stack_len);
			if (!ret)
				printf("Error\n");
			else
				printf("%i\n", ret);
		}
		free(stack);
	}
	else
		printf("Error\n");
	return (0);
}
