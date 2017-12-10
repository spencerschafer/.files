#include "libft.h"

void		ft_strrev(char *str)
{
	int		i;
	int		len;
	char	temp;
	
	i = 0;
	len = ft_strlen(str) - 1;
	while (i < (len + 1 / 2))
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		++i;
		--len;
	}
}
