#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	substr_len;
	size_t	output_index;

	substr_len = ft_strlen((char *)s) - start;
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	output = (char *)malloc(substr_len + 1 * sizeof(char));
	if (!output)
		return (NULL);
	output_index = 0;
	while (output_index < len)
	{
		output[output_index] = s[start];
		output_index++;
		start++;
	}
	output[output_index] = '\0';
	return (output);
}

// First 3 ticks 
// #include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*output;
// 	char	*s_temp;
// 	size_t	substr_len;
// 	size_t	output_index;

// 	s_temp = (char *)s;
// 	substr_len = ft_strlen(s_temp) - start;
// 	if (start > substr_len + 1
// 		|| start + len > substr_len + 1 || len < start)
// 		return (NULL);
// 	output = (char *)malloc(substr_len + 1 * sizeof(char));
// 	output_index = 0;
// 	while (output_index < len)
// 	{
// 		output[output_index] = s[start];
// 		output_index++;
// 		start++;
// 	}
// 	output[output_index] = '\0';
// 	return (output);
// 	return (NULL);
// }

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
	char	str[] = "lorem ipsum dolor sit amet";
	char	*strsub;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(strsub = ft_substr(str, 0, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		if (!(strsub = ft_substr(str, 7, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		if (!(strsub = ft_substr(str, 7, 0)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		if (!(strsub = ft_substr(str, 0, 0)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 5)
	{
		char *bullshit;
		if (!(strsub = ft_substr(str, 400, 20)))
			ft_print_result("NULL");
		else
		{
			bullshit = (char *)&strsub[30];
			bullshit = "FULL BULLSHIT";
			if (strsub)
				ft_print_result(strsub);
			else
				ft_print_result("rip");
		}
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
		(void)bullshit;
	}
	return (0);
}
