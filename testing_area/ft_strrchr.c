#include "libft.h"

char *ft_strrchr(const char *s,int c)
{
	int		index;
	char	*ptr;
	void	*output;

	ptr = (char *)s;
	index = 0;
	output = NULL;
	while (ptr[index] != '\0')
	{
		if (ptr[index] == c)
		{
			output = &ptr[index];
		}
		index++;
	}
	if (c == '\0' && ptr[index] == '\0')
		return (&ptr[index]);
	return (output);
}

int main(void)
{
	char str[9] = "Santiago";

	printf("%s\n", "strrchr:");
	printf("%s\n", strrchr(str, 'a'));

	printf("%s\n", "ft_strrchr:");
	printf("%s\n", ft_strrchr(str, 'a'));
}