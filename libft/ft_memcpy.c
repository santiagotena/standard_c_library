/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:08:40 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 17:47:15 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dst.  If dst 
 * and src overlap, behavior is undefined. Returns the original value of dst.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;
	char	*ptr_dst;
	char	*ptr_src;

	counter = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (counter < n)
	{
		ptr_dst[counter] = ptr_src[counter];
		counter++;
	}
	return (dst);
}
