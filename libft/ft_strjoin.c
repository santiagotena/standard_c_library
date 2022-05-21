/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:27:37 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/21 12:05:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is 
 * the result of the concatenation of ’s1’ and ’s2’.
 * 
 * Returns the new string or NULL if the allocation fails.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
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
