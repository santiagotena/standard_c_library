#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int main(void)
{
	printf("%s\n", "ft_isdigit:");
	printf("%d\n", ft_isdigit('6'));
	printf("%d\n", ft_isdigit(5));
	printf("%d\n", ft_isdigit('A'));
	printf("%s\n", "isdigit:");
	printf("%d\n", isdigit('6'));
	printf("%d\n", isdigit(5));
	printf("%d\n", isdigit('A'));

	return (0);
}