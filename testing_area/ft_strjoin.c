#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	output_index;
	size_t	index;

	output = (char *)malloc(ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1 * sizeof(char));
	if (!output)
		return (NULL);
	output_index = 0;
	index = 0;
	while (output_index < ft_strlen((char *)s1))
	{
		output[output_index] = s1[index];
		output_index++;
		index++;
	}
	index = 0;
	while (output_index < ft_strlen((char *)s1) + ft_strlen((char *)s2))
	{
		output[output_index] = s2[index];
		output_index++;
		index++;
	}
	output[output_index] = '\0';
	return (output);
}

#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		s1[0] = '\0';
		s2[0] = '\0';
		if (!(strjoin = ft_strjoin(s1, s2)))
			ft_print_result("NULL");
		else
			ft_print_result(strjoin);
		if (strjoin == s1 || strjoin == s2)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}
