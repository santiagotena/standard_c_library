#include "libft.h"

void 	*ft_memset(void *b, int c, size_t len)
{
	size_t	counter;
	char	*ptr;

	ptr = (char*)b;

	counter = 0;
	while (counter < len)
	{
		ptr[counter] = c;
		counter++;
	}
	return (b);
}

int main(void)
{
	char	str[15] = "Santiago Tena";
	int		c = '@';
	int		len = 8;

	memset(str, c, len);
	printf("%s\n", "memset:");
	printf("%s\n", str);
	
	// ft_memset(str, c, len);
	// printf("%s\n", "ft_memset:");
	// printf("%s\n", str);

	return (0);
}