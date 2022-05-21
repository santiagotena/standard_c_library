/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:25:16 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/21 12:10:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function ’f’ to each character of the string ’s’, 
 * and passing its index as first argument to create a new string 
 * (with malloc(3)) resulting from successive applications of ’f’.
 * 
 * Returns the string created from the successive applications of ’f’. 
 * Returns NULL if the allocation fails.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		index;

	output = (char *) malloc ((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		output[index] = f(index, s[index]);
		index++;
	}
	output[index] = '\0';
	return (output);
}

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

char	mapi(unsigned int i, char c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int		main(int argc, const char *argv[])
{
	char	*str;
	char	*strmapi;

	alarm(5);
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		strmapi = ft_strmapi(str, &mapi);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[11] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	return (0);
}

// char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
// {
// 	char *ptr;
// 	int i = 0;
	
// 	ptr = (char *) malloc ((ft_strlen((char *)s) + 1)* sizeof(char));
// 	if (!ptr)
// 	 	return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		ptr[i] = f(i, s[i]);
// 		//printf("ptr in func: %c\n", )
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }