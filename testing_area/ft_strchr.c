#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr;
	
	index = 0;
	while (ptr[index] != '\0')
	{
		if (ptr[index] == c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	if (c == '\0' || ptr[index] == '\0')
		return (&ptr[index]);
	return (NULL);
}

int main(void)
{
	char str[9] = "";

	printf("%s\n", "strchr:");
	printf("%s\n", strchr(str, '\0'));

	printf("%s\n", "ft_strchr:");
	printf("%s\n", ft_strchr(str, '\0'));
}