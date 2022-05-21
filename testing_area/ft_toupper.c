#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

int	main(void)
{
	printf("%s\n", "ft_toupper:");
	printf("%d\n", ft_toupper('a'));
	printf("%d\n", ft_toupper('A'));
	printf("%d\n", ft_toupper('5'));
	printf("%d\n", ft_toupper('/'));

	printf("%s\n", "toupper:");
	printf("%d\n", toupper('a'));
	printf("%d\n", toupper('A'));
	printf("%d\n", toupper('5'));
	printf("%d\n", toupper('/'));

	return (0);
}