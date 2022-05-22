/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/23 01:30:05 by stena-he         ###   ########.fr       */
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
	temp_s = strdup(s);
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

// int    ft_strlen(char str[])
// {
//     int        counter;

//     counter = 0;
//     while (str[counter] != '\0')
//     {
//         counter += 1;
//     }
//     return (counter);
// }

// char    *ft_strdup(const char *s1)
// {
//     int    count;
//     char    *output;
//     int    index;

//     index = 0;
//     count = 0;
//     while (s1[index] != '\0')
//     {
//         count++;
//         index++;
//     }
//     output = (char *)malloc((count + 1) * sizeof(char));
//     index = 0;
//     while (index < count)
//     {
//         output[index] = s1[index];
//         index++;
//     }
//     output[index] = '\0';
//     return (output);
// }

// char    **ft_split(char const *s, char c)
// {
//     char    **output;
//     int    index;
//     int        rows;
//     char    *temp_s;
//     char    *null_ptr;

//     index = 0;
//     rows = 0;
//     temp_s = ft_strdup(s);
//     //null_ptr = NULL;
//     while (index < ft_strlen((char *) s))
//     {
//         if (index == 0 && s[index] == c)
//         {
//             rows++;
//             continue ;
//         }    
//         if (s[index] == c && s[index - 1] != '0')
//             rows++;
//         if (s[index] == c)
//             temp_s[index] = '\0';
//         index++;
//     }
//     output = (char **) malloc((rows + 2 * 1) * sizeof(char *));
//     //if (!output)
//     //    return (NULL);
//     index = 0;
//     rows = 0;
//     while (index < ft_strlen((char *) s))
//     {
//         if (temp_s[index] != '\0')
//         {
//             output[rows][1] = ft_strdup(&temp_s[index]);
//             rows++;
//         }
//         index++;
//     }
//     output[index][1] = 0;
//     return (output);
// }

// int main(void)
// {
//   ft_split("a b c", ' ');
// }