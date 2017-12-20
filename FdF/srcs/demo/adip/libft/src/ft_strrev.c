#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	start;
	char	temp;

	start = 0;
	len = ft_strlen(str);
	while (start++ != len--)
	{
		temp = str[start];
		str[start] = str[len];
		str[len] = temp;
	}
	return (str);
}

