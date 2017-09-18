#include <unistd.h>

/*
 * [create a stack]
 * [iterate through string]
 * [when an open bracket is encountered add it to the stack]
 * [when a closed bracket is encountered check to see if it corresponds to the last bracket opened]
 * [if it does - remove open bracket from stack]
 * [else - return an error]
 * [if at the end of the string the stacks length is 0 - return OK, else - return Error]
 * [check length of the array is zero - otherwise odd number of open/closed brackets]
 */

int			ft_strlen(char *str)
{	
	int		len;
	
	len = 0;
	while (*str++) ++len;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/*
 * ft_brackets, takes a string, and an array that acts as a stack.
 * The function determines the length of the string. After which each value is initialised  to zero.
 * Then, the function iterates through the string until it reaches the end of the string (NULL).
 * During the iteration, it checks to see if the current value is equal to an open bracket.
 * If it is, it adds this open bracket to the stack. If the value is not an open bracket, but a closed bracket,
 * the function then checks that the previous bracket that was opened is the open equivalent of the closed bracket.
 * If it is the equivalent, the open bracket is removed from the stack and the value of I is then decremented.
 * If is not the equvalent, it returns an error.
 * 
 * i.e If an open bracket is ecountered, array[0] is assigned a value, and i is incremented by 1. This allows us
 * to add a new open bracket to the current value of i. Therefore, when a closed bracket is encountered, we check that
 * i - 1 is the equivalent open bracket. If it is, we then reassign this value to zero and continue forward in the string
 * Otherwise, we return an error.
 *
 * When the string reaches the end, we expect to have encountered the same amount of closing brackets as there are open
 * brackets. This is because each time an open bracket is encountered, the following bracket needs to be
 * either another open bracket, or the corresponding closing bracket. Thus at the end of the string, all open brackets
 * should have been closed, and thus removed from the array. This leaves the array with a total length of zero.
 *
 * If there were more open brackets than closed brackets, or vice versa, the length of the array will be more than 1.
 * Thus, returning an error.
 */
int		ft_brackets(char *str, int len)
{
	int		i;
	char	array[len];
	
	i = 0;
	while (i <= len)
		array[i++] = 0;
	i = 0;
	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			array[i++] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (*str == ')' && array[i - 1] == '(')
				array[--i] = '\0';
			else if (*str == ']' && array[i - 1] == '[')
				array[--i] = '\0';
			else if (*str == '}' && array[i - 1] == '{')
				array[--i] = '\0';
			else
				return (-1);
		}
		++str;
	}
	return ((len = ft_strlen(array) != 0) ? (-1) : (0));
}

/*
 *For each arguement, pass the arguement into ft_brackets along with an array.
 *The array is used as a stack.
 *If the value returned from brackets is -1, write "Error" to the stdout, else write "OK".
 *If there is less than 1 arguement, write only a '\n' to the stdout.
 */
int			main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i;
		int ret;
		int len;

		i = 1;
		while (i < argc)
		{
			len = ft_strlen(argv[i]);
			ret = ft_brackets(argv[i++], len);
			ft_putstr((ret == -1) ? "Error\n" : "OK\n");
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
