#include "rpn.h"

void	clear_buffer(char *buff, int len)
{
	int i;

	i = 0;
	while (i < len)
		buff[i++] = 0;
}
