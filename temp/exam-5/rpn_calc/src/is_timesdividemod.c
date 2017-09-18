#include "rpn.h"

int	is_timesdividemod(char c)
{
	if (c == '*' || c == '/' || c == '%')
		return (1);
	return(0);
}
