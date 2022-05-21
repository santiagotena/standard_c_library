/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:04:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/21 12:07:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
