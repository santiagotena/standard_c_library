/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 15:54:05 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:41:41 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c (converted to an 
 * unsigned char) in string s.
 * 
 * Returns a pointer to the byte located, or NULL if no such byte exists 
 * within n bytes.
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*ptr;

	ptr = (char *)s;
	index = 0;
	while (index < n)
	{
		if (ptr[index] == c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	return (NULL);
}
