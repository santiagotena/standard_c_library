/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:51:35 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:12:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted to a char) in the
 * string pointed to by s.  The terminating null character is considered to 
 * be part of the string; therefore if c is `\0', the functions locate the 
 * terminating `\0'. 
 * 
 * Returns a pointer to the located character, or NULL if the character 
 * does not appear in the string.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	ptr = (char *)s;
	index = 0;
	while (ptr[index] != '\0')
	{
		if (ptr[index] == c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	if (c == '\0' && ptr[index] == '\0')
		return (&ptr[index]);
	return (NULL);
}
