#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*output;
	size_t	index;

	index = 0;
	count = 0;
	while (s1[index] != '\0')
	{
		count++;
		index++;
	}
	output = (char *)malloc((count + 1) * sizeof(char));
	index = 0;
	while (index < count)
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}

// int main(void)
// {
// 	char	*str = "Santiago Tena";
// 	char	*str_dst;

// 	// printf("strdup:\n");
// 	// printf("Original's address: %p\n", &str);
// 	// str_dst = strdup(str);
// 	// printf("Copy string: %s\nIt's address: %p\n", str_dst, &str_dst);
// 	// free(str_dst);

// 	printf("ft_strdup:\n");
// 	printf("Original's address: %p\n", &str);
// 	str_dst = ft_strdup(str);
// 	printf("Copy string: %s\nIt's address: %p\n", str_dst, &str_dst);
// 	free(str_dst);

// 	return (0);
// }