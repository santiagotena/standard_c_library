#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		counter;

	counter = 0;
	while (counter < n)
	{
		if (s1[counter] != s2[counter])
		{
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		}		
		if (s1[counter] == '\0' && s2[counter] == '\0')
		{
			return (0);
		}
		counter++;
	}
	return (0);
}

int main(void)
{
	char str1[20] = "test\200";
	char str2[20] = "test\0";
	size_t n = 6;

	printf("%s\n", "strncmp:");
	printf("%d\n", strncmp(str1, str2, n));

	printf("%s\n", "ft_strncmp:");
	printf("%d\n", ft_strncmp(str1, str2, n));

	return (0);
}