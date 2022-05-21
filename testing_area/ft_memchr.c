#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*ptr;

	ptr = (char *)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	return (NULL);
}

int main(void)
{
	char	str[20] = "Santiago";
	int		c;
	size_t	n;

	c = 'o';
	n = 3;
	printf("%s\n", "ft_strncmp:");
	printf("%p\n", ft_memchr(str, c, n));
	
	printf("%s\n", "memchr:");
	printf("%p\n", memchr(str, c, n));
	return (0);
}