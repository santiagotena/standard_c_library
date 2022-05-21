#include "libft.h"

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <stdlib.h>
#include <unistd.h>

int		main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_putstr_fd("lorem ipsum dolor sit amet", 2);
	else if (arg == 2)
		ft_putstr_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
	else if (arg == 3)
		ft_putstr_fd("", 2);
	else if (arg == 4)
		ft_putstr_fd("lorem ipsum do\0lor sit amet", 1);
	return (0);
}