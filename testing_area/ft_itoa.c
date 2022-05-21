#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int	ft_int_length(int x)
{
	int		index;

	index = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		index++;
	}
	return (index);
}

char	*ft_char_output(int length, int minus, char *output, int n)
{
	while (length + minus >= 0)
	{
		output[length + minus] = n % 10 + '0';
		n = n / 10;
		if (length == 0 && minus == 1)
		{
			output[0] = '-';
			break ;
		}
		length--;
	}
	return (output);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the 
 * integer received as an argument. Negative numbers must be handled.
 * 
 * Returns the string representing the integer. NULL if the allocation fails.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n)
{
	char	*output;
	int		minus;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n = n * -1;
	}
	length = ft_int_length(n);
	output = (char *) malloc((length + minus + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[length + minus] = '\0';
	length--;
	output = ft_char_output(length, minus, output, n);
	return (output);
}


// int main(void)
// {
// 	printf("ft_itoa:\n");
// 	printf("%s", ft_itoa(0));
// }

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char *res = ft_itoa(0);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 2)
	{
		char *res = ft_itoa(9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 3)
	{
		char *res = ft_itoa(-9);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 4)
	{
		char *res = ft_itoa(10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 5)
	{
		char *res = ft_itoa(-10);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 6)
	{
		char *res = ft_itoa(8124);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 7)
	{
		char *res = ft_itoa(-9874);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 8)
	{
		char *res = ft_itoa(543000);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 9)
	{
		char *res = ft_itoa(-2147483648LL);
		ft_print_result(res);
		free(res);
	}
	else if (arg == 10)
	{
		char *res = ft_itoa(2147483647);
		ft_print_result(res);
		free(res);
	}
	return (0);
}
