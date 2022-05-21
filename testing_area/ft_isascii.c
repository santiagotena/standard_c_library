#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_isascii('L'));
	printf("%d\n", ft_isascii(76));
	printf("%d\n", ft_isascii('9'));
	printf("%d\n", ft_isascii(57));
	printf("%d\n", ft_isascii('/'));
	printf("%d\n", ft_isascii(47));
}