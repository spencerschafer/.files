#include "rpn.h"

void	ft_strcpy(char *dst, char *src)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
}
