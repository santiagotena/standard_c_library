#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	if (!dst || !src)
		return (0);
	while (src[counter] != '\0')
	{
		counter++;
	}
	if (dstsize == 0)
		return (counter);
	while (index < dstsize - 1 && src[index] != '\0')
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (counter);
}

int main(void)
{
	char	dst[14] = "Santiago Tena";
	char	src[16] = "";
	size_t	n = 5;

	printf("%s\n", "strlcpy:");
	printf("%s\n", dst);
	printf("Output: %lu\n", strlcpy(dst, src, n));
	printf("%s\n", dst);

	// printf("%s\n", "ft_strlcpy:");
	// printf("%s\n", dst);
	// printf("Output: %lu\n", ft_strlcpy(dst, src, n));
	// printf("%s\n", dst);
}

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// void	ft_print_result(int n)
// {
// 	char c;

// 	if (n >= 10)
// 		ft_print_result(n / 10);
// 	c = n % 10 + '0';
// 	write (1, &c, 1);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	*dest;
// 	int		arg;

// 	alarm(5);
// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	if ((arg = atoi(argv[1])) == 1)
// 	{
// 		ft_print_result(ft_strlcpy(dest, "lorem", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (atoi(argv[1]) == 2)
// 	{
// 		ft_print_result(ft_strlcpy(dest, "", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (atoi(argv[1]) == 3)
// 	{
// 		ft_print_result(ft_strlcpy(dest, "lorem ipsum", 3));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (atoi(argv[1]) == 4)
// 	{
// 		ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (atoi(argv[1]) == 5)
// 	{
// 		ft_print_result(ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	return (0);
// }
