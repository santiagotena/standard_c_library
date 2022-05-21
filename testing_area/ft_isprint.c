#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
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
	printf("%s\n", "ft_isprint:");
	printf("%d\n", ft_isprint(' '));
	printf("%d\n", ft_isprint(32));
	printf("%d\n", ft_isprint('9'));
	printf("%d\n", ft_isprint(57));
	printf("%d\n", ft_isprint('/'));
	printf("%d\n", ft_isprint(47));

	printf("%s\n", "isprint:");
	printf("%d\n", isprint(' '));
	printf("%d\n", isprint(32));
	printf("%d\n", isprint('9'));
	printf("%d\n", isprint(57));
	printf("%d\n", isprint('/'));
	printf("%d\n", isprint(47));
}