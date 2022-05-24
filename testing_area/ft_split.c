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

// Main
// int main(void)
// {
//     int count_strings = 7;
//     char **split_strings = ft_split("abc def ghi", ' ');

//     // print out the substrings, which should be each word of the sentence above
//     for (int i = 0; i < count_strings; i++)
//         printf("%s\n", split_strings[i]);

//     // free the dynamically allocated space for each string
//     for (int i = 0; i < count_strings; i++)
//         free(split_strings[i]);

//     // free the dynamically allocated space for the array of pointers to strings
//     free(split_strings);

//   return 0;
// }

// Debugger

// int main(void) {
//     int count_strings = 7;
//     char **split_strings = ft_split("abc def ghi", ' ');

//     // print out the substrings, which should be each word of the sentence above
//     for (int i = 0; i < count_strings; i++)
//         printf("%s\n", split_strings[i]);

//     // free the dynamically allocated space for each string
//     for (int i = 0; i < count_strings; i++)
//         free(split_strings[i]);

//     // free the dynamically allocated space for the array of pointers to strings
//     free(split_strings);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// size_t ft_strlen(const char *str) {
//     int counter;

//     counter = 0;
//     while (str[counter] != '\0') {
//         counter += 1;
//     }
//     return (counter);
// }

// char *ft_strdup(const char *s1) {
//     int count;
//     char *output;
//     int index;

//     index = 0;
//     count = 0;
//     while (s1[index] != '\0') {
//         count++;
//         index++;
//     }
//     output = (char *)malloc((count + 1) * sizeof(char));
//     index = 0;
//     while (index < count) {
//         output[index] = s1[index];
//         index++;
//     }
//     output[index] = '\0';
//     return (output);
// }