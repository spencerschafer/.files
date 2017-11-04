#include "rpn.h"

int	check_int(long n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (1);
	return (0);
}
