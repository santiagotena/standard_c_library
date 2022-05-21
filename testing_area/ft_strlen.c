#include "libft.h"

size_t	ft_strlen(char str[])
{
	size_t		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}

// int main(void)
// {
// 	char str[6] = "Hello";
// 	printf("%lu\n", strlen(str));
// 	printf("%lu\n", ft_strlen(str));	
// 	return (0);
// }