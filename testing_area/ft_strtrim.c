#include "libft.h"

size_t	ft_forward(size_t s1_index, char *output,
					size_t set_index, char const *set)
{
	int		match;

	match = 0;
	while (s1_index < ft_strlen((char *) output) && output[s1_index] != '\0')
	{
		while (set_index < ft_strlen((char *) set))
		{
			if (output[s1_index] == set[set_index])
			{
				s1_index++;
				match = 1;
			}
			set_index++;
		}
		set_index = 0;
		if (match == 0)
			break ;
		match = 0;
	}
	return (s1_index);
}

void	ft_reverse(size_t rev_s1_index, size_t set_index,
					char const *set, char *output)
{
	int		match;

	match = 0;
	while (rev_s1_index > 0)
	{
		while (set_index < ft_strlen((char *) set))
		{
			if (output[rev_s1_index] == set[set_index])
			{
				output[rev_s1_index] = '\0';
				rev_s1_index--;
				match = 1;
			}
			set_index++;
		}
		set_index = 0;
		if (match == 0)
			break ;
		match = 0;
	}
}

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’ with the 
 * characters specified in ’set’ removed from the beginning and the end 
 * of the string.
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	size_t	s1_index;
	size_t	rev_s1_index;
	size_t	set_index;

	output = (char *) s1;
	s1_index = 0;
	rev_s1_index = ft_strlen((char *) s1) - 1;
	set_index = 0;
	s1_index = ft_forward(s1_index, output, set_index, set);
	ft_reverse(rev_s1_index, set_index, set, output);
	if (!output)
		return (NULL);
	return (ft_strdup(&output[s1_index]));
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
	char	*strtrim;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		if (!(strtrim = ft_strtrim(s1, " ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "te")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		char s1[] = " lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "l ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		char s1[] = "lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1, "tel")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 5)
	{
		char s1[] = "          ";
		if (!(strtrim = ft_strtrim(s1, " ")))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}
