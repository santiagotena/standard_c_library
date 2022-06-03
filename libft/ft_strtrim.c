/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:04:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/06/04 00:18:38 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_forward(size_t s1_index, char *output, \
	size_t set_index, char const *set)
{
	int		match;

	match = 0;
	while (s1_index < ft_strlen(output) && output[s1_index] != '\0')
	{
		while (set_index < ft_strlen(set))
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

static size_t	ft_reverse(size_t rev_s1_index, size_t set_index,\
	char const *set, char *output)
{
	int		match;

	match = 0;
	while (rev_s1_index >= 0)
	{
		while (set_index < ft_strlen(set))
		{
			if (output[rev_s1_index] == set[set_index])
			{
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
	return (rev_s1_index);
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
	rev_s1_index = ft_strlen(s1) - 1;
	set_index = 0;
	s1_index = ft_forward(s1_index, output, set_index, set);
	rev_s1_index = ft_reverse(rev_s1_index, set_index, set, output);
	output = ft_substr(s1, s1_index, rev_s1_index - s1_index + 1);
	if (!output)
		return (NULL);
	return (output);
}

//Debugger

size_t	ft_strlen(const char *str)
{
	size_t		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	substr_len;
	size_t	output_index;

	if (s == NULL)
		return (NULL);
	substr_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t) ft_strlen(s) < len)
		len = ft_strlen(s);
	output = (char *)malloc(substr_len * sizeof(char));
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
	if (!output)
		return (NULL);
	index = 0;
	while (index < count)
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int main(void)
{
	char s1[] = " lorem ipsum dolor sit amet";
	printf("%s\n", s1);
	printf("%s\n", ft_strtrim(s1, "l "));
	return (0);
}