#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_counter;
	size_t	src_counter;
	size_t	dst_size;
	char	*temp_src;

	dst_counter = 0;
	src_counter = 0;
	temp_src = (char *)src;
	while (src[src_counter] != '\0')
		src_counter++;
	while (dst[dst_counter] != '\0')
	{
		if (dstsize - 1 == dst_counter)
			return (src_counter + dst_counter + 1);
		dst_counter++;
	}
	dst_size = dst_counter;
	if (dstsize < dst_counter)
		return (src_counter + dstsize);
	while (dst_counter < dstsize - 1 && temp_src != (void *)0)
	{
		dst = temp_src;
		dst++;
		temp_src++;
		dst_counter++;
	}
	dst[dst_counter] = '\0';
	return (src_counter + dst_size);
}

// int main(void)
// {
// 	char	dst[100] = "Santiago ";
// 	char	src[100] = "Quack";
// 	size_t	n = 15;

// 	// char	*dest;

// 	// dest[14] = 'a';

// 	// printf("%s\n", "strlcat:");
// 	// printf("%s\n", dst);
// 	// printf("Output: %lu\n", strlcat(dst, src, n));
// 	// printf("%s\n", dst);

// 	printf("ft_strlcat:\n");
// 	printf("%s\n", dst);
// 	printf("Output: %lu\n", ft_strlcat(dst, src, n));
// 	printf("%s\n", dst);
// }

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;

	alarm(5);
	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		write(1, dest, 15);
		write(1, "\n", 1);
		ft_print_result(strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 2)
	{
		ft_print_result(strlcat(dest, "", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		ft_print_result(strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		write(1, dest, 15);
		write(1, "\n", 1);
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	else if (arg == 9)
	{
		memset(dest, 'r', 14);
		ft_print_result(strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
	}
	return (0);
}
