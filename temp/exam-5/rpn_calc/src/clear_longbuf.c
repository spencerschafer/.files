#include "rpn.h"

void	clear_longbuf(long *buff, int len)
{
	int i;

	i = 0;
	while (i < len)
		buff[i++] = 0;
}
