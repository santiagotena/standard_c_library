#include "libft.h"

int	ft_atoi(const char *str)
{
	int		output;
	int		sign;
	int		index;

	output = 0;
	sign = 1;
	index = 0;
	while (str[index] != '\0' && (str[index] >= 9 && str[index] <= 13 || str[index] == 20))
	{
		index++;
	}
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (sign * output);
		output = output * 10 + (str[index] - '0');
		index++;
	}
	return (sign * output);
}

int main(void)
{
	const char *str = "\n\n\n  -46\b9 \n5d6";

	printf("%s\n", "atoi:");
	printf("%d\n", atoi(str));

	printf("%s\n", "ft_atoi:");
	printf("%d\n", ft_atoi(str));
	return (0);
}