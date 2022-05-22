/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/23 01:07:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings 
 * obtained by splitting ’s’ using the character ’c’ as a delimiter. The 
 * array must end with a NULL pointer.
 * 
 * The array of new strings resulting from the split. NULL if the 
 * allocation fails.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c)
{
	char	**output;
	size_t	index;
	int		rows;
	char	*temp_s;
	char	*null_ptr;

	index = 0;
	rows = 0;
	temp_s = (char *) s;
	null_ptr = NULL;
	while (index < ft_strlen((char *) s))
	{
		if (index == 0 && s[index] == c)
		{
			rows++;
			continue ;
		}	
		if (s[index] == c && s[index - 1] != '0')
			rows++;
		if (s[index] == c)
			temp_s[index] = '\0';
		index++;
	}
	output = (char **) malloc((rows + 2 * 1) * sizeof(char *));
	if (!output)
		return (NULL);
	index = 0;
	rows = 0;
	while (index < ft_strlen((char *) s))
	{
		if (temp_s[index] != '\0')
		{
			output[rows][1] = *ft_strdup(&temp_s[index]);
			rows++;
		}
		index++;
	}
	output[rows][1] = *null_ptr;
	return (output);
}

///

// #include <stdlib.h>
// #include <unistd.h>

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	**tabstr;
// 	int		i;
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	i = 0;
// 	if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(tabstr = ft_split("          ", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 2)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 3)
// 	{
// 		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 4)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 5)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 6)
// 	{
// 		if (!(tabstr = ft_split("", 'z')))
// 			ft_print_result("NULL");
// 		else
// 			if (!tabstr[0])
// 				ft_print_result("ok\n");
// 	}
// 	return (0);
// }
