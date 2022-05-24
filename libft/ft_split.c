/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/24 09:15:37 by stena-he         ###   ########.fr       */
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
char    **ft_split(char const *s, char c)
{
    char    **array;
    size_t        index;
    int        rows;
    char    *temp_s;
    size_t        length;

    index = 0;
    rows = 1;
    temp_s = ft_strdup(s);
    length = ft_strlen(s);
    while (index < length)
    {
        if (s[index] != c && index == 0)
          rows++;
        if (s[index] == c && index == 0)
          {
            temp_s[index] = '\0';
            rows++;
          }
        else if (s[index] == c)
            temp_s[index] = '\0';
        else if (s[index] != c && s[index - 1] == c)
            rows++;
        index++;
    }
    array = (char **) calloc(rows , sizeof(char *)); // Was rows + 1
    if (!array)
        return (NULL);
    index = 0;
    rows = 0;
    while (index < length) // Start
    {
        //if (index == 0 && temp_s[index] != '\0')
        //    rows++;
        if (temp_s[index] != '\0')
        {
            array[rows] = ft_strdup(temp_s+index);
            index = index + ft_strlen(temp_s+index);
            rows++;
        }
        index++;
    }
    array[rows] = NULL;
    return (array);
}

// #include "libft.h"

// // size_t	ft_strlen(const char *str)
// // {
// //     int        counter;

// //     counter = 0;
// //     while (str[counter] != '\0')
// //     {
// //         counter += 1;
// //     }
// //     return (counter);
// // }

// // char    *ft_strdup(const char *s1)
// // {
// //     int		count;
// //     char	*output;
// //     int		index;

// //     index = 0;
// //     count = 0;
// //     while (s1[index] != '\0')
// //     {
// //         count++;
// //         index++;
// //     }
// //     output = (char *)malloc((count + 1) * sizeof(char));
// //     index = 0;
// //     while (index < count)
// //     {
// //         output[index] = s1[index];
// //         index++;
// //     }
// //     output[index] = '\0';
// //     return (output);
// // }

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
// char    **ft_split(char const *s, char c)
// {
//     char    **array;
//     size_t        index;
//     int        rows;
//     char    *temp_s;
//     size_t        length;

//     index = 0;
//     rows = 1;
//     temp_s = ft_strdup(s);
//     length = ft_strlen(s);
//     while (index < length)
//     {
//         if (s[index] != c && index == 0)
//           rows++;
//         if (s[index] == c && index == 0)
//           {
//             temp_s[index] = '\0';
//             rows++;
//           }
//         else if (s[index] == c)
//             temp_s[index] = '\0';
//         else if (s[index] != c && s[index - 1] == c)
//             rows++;
//         index++;
//     }
//     array = (char **) calloc(rows , sizeof(char *)); // Was rows + 1
//     if (!array)
//         return (NULL);
//     index = 0;
//     rows = 0;
//     while (index < length) // Start
//     {
//         //if (index == 0 && temp_s[index] != '\0')
//         //    rows++;
//         if (temp_s[index] != '\0')
//         {
//             array[rows] = ft_strdup(temp_s+index);
//             index = index + ft_strlen(temp_s+index);
//             rows++;
//         }
//         index++;
//     }
//     array[rows] = NULL;
//     return (array);
// }
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
// char    **ft_split(char const *s, char c)
// {
//     char    **array;
//     size_t        index;
//     int        rows;
//     char    *temp_s;
//     size_t        length;

//     index = 0;
//     rows = 1;
//     temp_s = ft_strdup(s);
//     length = ft_strlen(s);
//     while (index < length)
//     {
//         if (s[index] != c && index == 0)
//           rows++;
//         if (s[index] == c && index == 0)
//           {
//             temp_s[index] = '\0';
//             rows++;
//           }
//         else if (s[index] == c)
//             temp_s[index] = '\0';
//         else if (s[index] != c && s[index - 1] == c)
//             rows++;
//         index++;
//     }
//     array = (char **) calloc(rows , sizeof(char *)); // Was rows + 1
//     if (!array)
//         return (NULL);
//     index = 0;
//     rows = 0;
//     while (index < length) // Start
//     {
//         //if (index == 0 && temp_s[index] != '\0')
//         //    rows++;
//         if (temp_s[index] != '\0')
//         {
//             array[rows] = ft_strdup(temp_s+index);
//             index = index + ft_strlen(temp_s+index);
//             rows++;
//         }
//         index++;
//     }
//     array[rows] = NULL;
//     return (array);
// }

// int    main(void)
// {
//     ft_split("aaa", 'a');
//     return (0);
// }

// int	main(void)
// {
// 	ft_split("abc def ghi", ' ');
// 	return (0);
// }

///////////// Python Tutor

// # include <ctype.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <string.h>
// # include <unistd.h>

// size_t    ft_strlen(const char *str)
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
//     int        count;
//     char    *output;
//     int        index;

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
// char    **ft_split(char const *s, char c)
// {
//     char    **array;
//     size_t        index;
//     int        rows;
//     char    *temp_s;
//     size_t        length;

//     index = 0;
//     rows = 1;
//     temp_s = ft_strdup(s);
//     length = ft_strlen(s);
//     while (index < length)
//     {
//         if (s[index] == c && index == 0)
//             temp_s[index] = '\0';
//         else if (s[index] == c)
//             temp_s[index] = '\0';
//         else if (s[index] != c && s[index - 1] == c)
//             rows++;
//         index++;
//     }
//     array = (char **) malloc(rows * sizeof(char *)); // Was rows + 1
//     if (!array)
//         return (NULL);
//     index = 0;
//     rows = 0;
//     while (index < length)
//     {
//         if (temp_s[index] != '\0')
//         {
//             array[rows] = ft_strdup(temp_s+index);
//             index = index + ft_strlen(temp_s+index);
//             rows++;
//         }
//         index++;
//     }
//     array[rows] = NULL;
//     return (array);
// }

// int    main(void)
// {
//     ft_split("abc def ghi", ' ');
//     return (0);
// }