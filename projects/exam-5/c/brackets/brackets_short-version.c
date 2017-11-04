#include <unistd.h>

int			ft_strlen(char *str)
{	
	int		len = 0;;
	
	while (*str++) ++len;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_brackets(char *str)
{
	int		i = 0;
	int		len = ft_strlen(str);
	char	array[len];

	while (i <= len) array[i++] = 0;
	i = 0;
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{') array[i++] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (*str == ')' && array[i - 1] == '(') array[--i] = '\0';
			else if (*str == ']' && array[i - 1] == '[') array[--i] = '\0';
			else if (*str == '}' && array[i - 1] == '{') array[--i] = '\0';
			else return (-1);
		}
		++str;
	}
	return ((len = ft_strlen(array) != 0) ? (-1) : (0));
}

int			main(int argc, char *argv[])
{
	if (argc > 1)
		for (int i = 1; i < argc; ++i)	
			ft_putstr(((ft_brackets(argv[i])) == -1) ? "Error\n" : "OK\n");
	else
		ft_putstr("\n");
}
