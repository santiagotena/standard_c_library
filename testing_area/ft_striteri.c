#include "libft.h"

/**
 * @brief Applies the function ’f’ on each character of the string passed 
 * as argument, passing its index as first argument.  Each character is passed 
 * by address to ’f’ to be modified if necessary.
 * 
 * @param s 
 * @param f 
 */
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*output;
	int		index;

	output = (char *) malloc ((ft_strlen((char *)s) + 1) * sizeof(char));
	index = 0;
	if (!output)
		return (NULL);
	while (s[index] != '\0')
	{
		output[index] = f(index, s[index]);
		index++;
	}
	output[index] = '\0';
}

//

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	iter(unsigned int i, char *c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	return (0);
}
