/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:43:17 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/22 08:53:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int digit, int fd)
{
	int		out;

	out = digit + '0';
	write(fd, &out, 1);
}

void	recursion(int n, int fd)
{
	if (n > 9)
	{
		n = n / 10;
		recursion(n, fd);
		ft_putchar(n % 10, fd);
	}
}

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 * 
 * @param n 
 * @param fd 
 */
void 	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	recursion(n, fd);
	ft_putchar(n % 10, fd);
}

// int main(void)
// {
// 	ft_putnbr_fd(2147483647, 1);
// }

// int		main(int argc, const char *argv[])
// {
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 		ft_putnbr_fd(0, 1);
// 	else if (arg == 2)
// 		ft_putnbr_fd(5, 1);
// 	else if (arg == 3)
// 		ft_putnbr_fd(-5, 1);
// 	else if (arg == 4)
// 		ft_putnbr_fd(42, 1);
// 	else if (arg == 5)
// 		ft_putnbr_fd(-57, 1);
// 	else if (arg == 6)
// 		ft_putnbr_fd(164189, 1);
// 	else if (arg == 7)
// 		ft_putnbr_fd(-987441, 1);
// 	else if (arg == 8)
// 		ft_putnbr_fd(2147483647, 1);
// 	else if (arg == 9)
// 		ft_putnbr_fd(-2147483648LL, 1);
// 	return (0);
// }

