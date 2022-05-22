/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:38:55 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/18 18:03:27 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate strings with the same input parameters and output 
 * result as snprintf(3). Takes the full size of the destination buffer and 
 * guarantees NUL-termination if there is room. Note that room for the NUL 
 * should be included in dstsize. 
 * 
 * Appends string src to the end of dst. It will append at most 
 * dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, 
 * unless dstsize is 0 or the original dst string was longer than dstsize 
 * (in practice this should not happen as it means that either dstsize 
 * is incorrect or that dst is not a proper string). 
 * 
 * If the src and dst strings overlap, the behavior is undefined.
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_counter;
	size_t	src_index;
	size_t	dst_size;

	dst_counter = 0;
	src_index = 0;
	while (dst[dst_counter] != '\0')
	{
		if (dstsize - 1 == dst_counter)
			return (ft_strlen((char *)src) + dst_counter + 1);
		dst_counter++;
	}
	dst_size = dst_counter;
	if (dstsize < dst_counter)
		return (ft_strlen((char *)src) + dstsize);
	while (dst_counter < dstsize - 1 && src[src_index] != '\0')
	{
		dst[dst_counter] = src[src_index];
		dst_counter++;
		src_index++;
	}
	dst[dst_counter] = '\0';
	return (ft_strlen((char *)src) + dst_size);
}