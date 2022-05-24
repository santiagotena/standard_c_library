/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 09:22:00 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/24 13:36:58 by stena-he         ###   ########.fr       */
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
char **ft_split(char const *s, char c) {
    char **array;
    size_t index;
    int rows;
    char *temp_s;
    size_t length;

    index = 0;
    rows = 0;
    temp_s = ft_strdup(s);
    length = ft_strlen(s);
    while (index < length) {
        if (s[index] != c && index == 0)
            rows++;
        if (index != 0)
            if (s[index] != c && s[index - 1] == c)
                rows++;
        index++;
    }
    array = (char **)calloc(rows + 1, sizeof(char *));
    if (!array)
        return (NULL);

    index = 0;

    while (index < length) {
        if (temp_s[index] == c)
            temp_s[index] = '\0';
        index++;
    }

    index = 0;
    rows = 0;
    while (index < length) {
        if (temp_s[index] != '\0') {
            array[rows] = ft_strdup(temp_s + index);
            index = index + ft_strlen(temp_s + index);
            rows++;
        }
        index++;
    }
    array[rows] = 0;
    return (array);
}
