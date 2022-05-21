#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*ptr;

	ptr = (char*)s;
	counter = 0;
	while (counter < n)
	{
		if (ptr[counter] != 0)
			ptr[counter] = 0;
		counter++;
	}
}

int main(void)
{
	char	str[20] = "Santi0go Tena";
	int		n = 2;
	int		i;

	bzero(str+11, n);
	printf("%s\n", "bzero:");
	for (i = 0; i <= 20; i++)
	{
		printf("%c", str[i]);
	}	
	printf("%s", "\n");

	ft_bzero(str+11, n);
	printf("%s\n", "ft_bzero:");
	for (i = 0; i <= 20; i++)
	{
		printf("%c", str[i]);
	}
	printf("%s", "\n");
	return (0);
}