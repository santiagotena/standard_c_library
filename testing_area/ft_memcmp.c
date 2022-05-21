#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	counter;
	char	*ptr1;
	char	*ptr2;

	counter = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (counter < n)
	{
		if (ptr1[counter] != ptr2[counter])
		{
			return ((unsigned char)ptr1[counter] - (unsigned char)ptr2[counter]);
		}
		counter++;
	}
	return (0);
}

int main(void)
{
	char str1[9] = "Santiago";
	char str2[9] = "SantiaGo";
	size_t n = 9;

	printf("%s\n", "memcmp:");
	printf("%d\n", memcmp(str1, str2, n));

	printf("%s\n", "ft_memcmp:");
	printf("%d\n", ft_memcmp(str1, str2, n));
	return (0);
}