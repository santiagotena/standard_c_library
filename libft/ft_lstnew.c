/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:08:45 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/26 18:33:48 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member 
 * variable ’content’ is initialized with the value of the parameter 
 * ’content’. The variable ’next’ is initialized to NULL.
 * 
 * Returns the new node.
 * @param content The content to create the node with.
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	result->content = content;
	result->next = NULL;
	return (result);
}
