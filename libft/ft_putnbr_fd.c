/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:43:17 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/21 23:58:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param n 
 * @param fd 
 */
void 	ft_putnbr_fd(int n, int fd)
{
	int		length;
	int		temp_n;

	length = 0;
	temp_n = n;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	
	if (temp_n == 0)
		length = 1;
	else
	{
		while (temp_n != 0)
		{
			temp_n /= 10;
			length++;
		}
	}
	write(fd, &n, length);
}

int main(void)
{
	ft_putnbr_fd(-2147483648, 1);
}