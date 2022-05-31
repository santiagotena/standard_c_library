/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:18:27 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/31 15:11:59 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rowcounter(char const *s, char c, size_t length)
{
	size_t	index;
	int		rows;

	index = 0;
	rows = 0;
	while (index < length)
	{
		if (s[index] != c && index == 0)
			rows++;
		if (index != 0)
			if (s[index] != c && s[index - 1] == c)
				rows++;
		index++;
	}
	return (rows);
}

void	ft_insertnull(size_t length, char *temp_s, char c)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		if (temp_s[index] == c)
			temp_s[index] = '\0';
		index++;
	}
}

int	ft_arrfill(char *temp_s, char **array, size_t length)
{
	size_t	index;
	int		rows;

	index = 0;
	rows = 0;
	while (index < length)
	{
		if (temp_s[index] != '\0')
		{
			array[rows] = ft_strdup(temp_s + index);
			index = index + ft_strlen(temp_s + index);
			rows++;
		}
		index++;
	}
	return (rows);
}

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
	char	**array;
	int		rows;
	char	*temp_s;
	size_t	length;

	temp_s = ft_strdup(s);
	length = ft_strlen(s);
	rows = ft_rowcounter(s, c, length);
	array = (char **)ft_calloc(rows + 1, sizeof(char *));
	if (!array)
		return (NULL);
	ft_insertnull(length, temp_s, c);
	rows = ft_arrfill(temp_s, array, length);
	array[rows] = 0;
	return (array);
}
