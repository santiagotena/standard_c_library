#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;
	char	*ptr_dst;
	char	*ptr_src;
	
	counter = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (counter < n)
	{
		ptr_dst[counter] = ptr_src[counter];
		counter++;
	}
	return (dst);
}

int main(void)
{
	char	dst[14] = "Santiago Tena";
	// char	src[6] = "Quack";
	size_t	n = 5;

	printf("%s\n", "ft_memcpy:");
	printf("Previous to ft_memcpy: %s\n", dst);
	ft_memcpy(dst, dst+2, n);
	printf("After ft_memcpy: %s\n", dst);

	// printf("%s\n", "memcpy:");
	// printf("Previous to memcpy: %s\n", dst);
	// memcpy(dst, dst+2, n);
	// printf("After memcpy: %s\n", dst);

	return (0);
}