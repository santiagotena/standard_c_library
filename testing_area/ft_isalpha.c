#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("%s\n", "ft_isalpha:");
	printf("%d\n", ft_isalpha('L'));
	printf("%d\n", ft_isalpha(76));
	printf("%d\n", ft_isalpha('9'));
	printf("%d\n", ft_isalpha(57));
	printf("%d\n", ft_isalpha(69));


	printf("%s\n", "isalpha:");
	printf("%d\n", isalpha('L'));
	printf("%d\n", isalpha(76));
	printf("%d\n", isalpha('9'));
	printf("%d\n", isalpha(57));
	printf("%d\n", ft_isalpha(69));

	return (0);
}