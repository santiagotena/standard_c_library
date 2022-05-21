#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
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
	printf("%d\n", ft_isalnum('L'));
	printf("%d\n", ft_isalnum(76));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", ft_isalnum(57));
	printf("%d\n", ft_isalnum('/'));
	printf("%d\n", ft_isalnum(47));
}
