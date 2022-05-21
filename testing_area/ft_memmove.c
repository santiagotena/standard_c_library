#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;
	int		rev_index;
	char	*ptr_dst;
	char	*ptr_src;

	counter = 0;
	rev_index = len-1;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (dst < src)
	{
		while (counter < len)
		{
		ptr_dst[counter] = ptr_src[counter];
		counter++;
		}
		return (dst);
	}
	while (counter < len)
	{
		ptr_dst[rev_index] = ptr_src[rev_index];
		counter++;
		rev_index--;
	}
	return (dst);
}

int	main(void)
{
	char	dst[14] = "Santiago Tena";
	// char	src[6] = "Quack";
	size_t	len = 5;

	printf("%s\n", "ft_memmove:");
	printf("Previous to ft_memmove: %s\n", dst);
	ft_memmove(dst, dst+2, len);
	printf("After ft_memmove: %s\n", dst);
	
	// printf("%s\n", "memmove:");
	// printf("Previous to memmove: %s\n", dst);
	// memmove(dst+2, dst, len);
	// printf("After memmove: %s\n", dst);

	return (0);
}