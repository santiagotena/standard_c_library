#include "libft.h"

size_t	ft_needlelen(const char *needle, size_t	index, size_t counter)
{
	while (needle[index] != '\0' )
	{
		index++;
		counter++;
	}
	return (counter);
}

char	*ft_outputassign(const char *haystack, size_t index)
{
	char	*temp_output;

	temp_output = (char *)haystack;
	return (&temp_output[index]);
}

void	ft_counter_reset(size_t	*sub_index, size_t	*match_counter)
{
	*sub_index = -1;
	*match_counter = -1;
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	sub_index;
	size_t	counter;
	size_t	match_counter;
	char	*output;

	index = 0;
	sub_index = 0;
	match_counter = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	counter = ft_needlelen(needle, index, 0);
	while (index < len && haystack[index] != '\0')
	{
		if (haystack[index] == needle[sub_index] && sub_index == 0)
			output = ft_outputassign(haystack, index);
		if (haystack[index] != needle[sub_index])
			ft_counter_reset(&sub_index, &match_counter);
		sub_index++;
		match_counter++;
		if (match_counter == counter)
			return (output);
		index++;
	}
	return (NULL);
}

int main(void)
{
	char	*haystack = "Santiago Tena Hernandez";
	char	*needle = "Tena";
	size_t	len;

	len = 23;
	// printf("strnstr:\n");
	// printf("%s\n", strnstr(haystack, needle, len));

	printf("ft_strnstr:\n");
	printf("%s\n", ft_strnstr(haystack, needle, len));

	return (0);
}