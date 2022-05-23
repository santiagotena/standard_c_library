/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/23 19:47:46 by stena-he         ###   ########.fr       */
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
	int		length;
	int		count;
	int		index;
	int		previous_index;
	char 	**strings;
	char 	*buffer;
	int 	string_index;

	length = ft_strlen((char *) s);
	count = 0;
	index = 0;
	buffer = malloc (1000 * sizeof(char));
	string_index = 0;
	while (index < length)
	{
		while (index < length)
		{
		if (s[index] != c)
			break;
		index++;
		}
		
		previous_index = index;
		while (index < length)
		{
		if (s[index] == c)
			break;
		index++;
		}
		if (index > previous_index) 
			count++;
	}
	strings = malloc(sizeof(char *) * count);
	index = 0;
	while (index < length)
	{
		while (index < length)
		{
		if (s[index] != c)
			break;
		index++;
		}
		
		// store the next substring into the buffer char array, use j to keep 
		// track of the index in the buffer array to store the next char
		int buffer_index = 0;
		while (index < length)
		{
		if (s[index] == c)
			break;
		
		buffer[buffer_index] = s[index];
		index++;
		buffer_index++;
		}
		
		// only copy the substring into the array of substrings if we actually 
		// read in characters with the above loop... it's possible we won't if 
		// the string ends with a group of separator characters!
		if (buffer_index > 0)
		{
		// add a null terminator on to the end of buffer to terminate the string
		buffer[buffer_index] = '\0';
		
		// allocate enough space using malloc, store the pointer into the strings 
		// array of pointers at hte current string_index
		strings[string_index] = malloc((ft_strlen(buffer) + 1) * sizeof(char));
		
		// copy the buffer into this dynamically allocated space 
		strcpy(strings[string_index], buffer);
		
		// advance string_index so we store the next string at the next index in 
		// the strings array
		string_index++;
		}
	}

	// return our array of strings  
	return strings;
}

// int		main(void)
// {
// 	char s[] = "To be, or not to be, that is the question.";
// 	int count_strings = 0;
// 	char **split_strings = ft_split(s, ' ');
	
// 	// print out the substrings, which should be each word of the sentence above
// 	for (int i = 0; i < count_strings; i++)
// 		printf("%s\n", split_strings[i]);
	
// 	// free the dynamically allocated space for each string
// 	for (int i = 0; i < count_strings; i++)
// 		free(split_strings[i]);
	
// 	// free the dynamically allocated space for the array of pointers to strings
// 	free(split_strings);
	
// 	return 0;
// }

// Original attempt
// #include "libft.h"

// /**
//  * @brief Allocates (with malloc(3)) and returns an array of strings 
//  * obtained by splitting ’s’ using the character ’c’ as a delimiter. The 
//  * array must end with a NULL pointer.
//  * 
//  * The array of new strings resulting from the split. NULL if the 
//  * allocation fails.
//  * 
//  * @param s 
//  * @param c 
//  * @return char** 
//  */
// char	**ft_split(char const *s, char c)
// {
// 	char	**output;
// 	size_t	index;
// 	int		rows;
// 	char	*temp_s;
// 	char	*null_ptr;

// 	index = 0;
// 	rows = 0;
// 	temp_s = strdup(s);
// 	null_ptr = NULL;
// 	while (index < ft_strlen((char *) s))
// 	{
// 		if (index == 0 && s[index] == c)
// 		{
// 			rows++;
// 			continue ;
// 		}	
// 		if (s[index] == c && s[index - 1] != '0')
// 			rows++;
// 		if (s[index] == c)
// 			temp_s[index] = '\0';
// 		index++;
// 	}
// 	output = (char **) malloc((rows + 2 * 1) * sizeof(char *));
// 	if (!output)
// 		return (NULL);
// 	index = 0;
// 	rows = 0;
// 	while (index < ft_strlen((char *) s))
// 	{
// 		if (temp_s[index] != '\0')
// 		{
// 			output[rows][1] = *ft_strdup(&temp_s[index]);
// 			rows++;
// 		}
// 		index++;
// 	}
// 	output[rows][1] = *null_ptr;
// 	return (output);
// }

// int main(void)
// {
//   ft_split("a b c", ' ');
// }

//// Python Tutor

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
//     char	**output;
//     int		index;
//     int		rows;
//     char	*temp_s;
//     char    *null_ptr;
// 	char	length;

//     index = 0;
//     rows = 0;
//     temp_s = ft_strdup(s);
// 	length = ft_strlen((char *) s);
//     //null_ptr = NULL;
//     while (index < length)
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
//     while (index < length)
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

/////

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
