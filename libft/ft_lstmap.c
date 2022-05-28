/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:56:32 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/28 12:09:09 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ on the 
 * content of each node.  Creates a new list resulting of the successive 
 * applications of the function ’f’.  The ’del’ function is used to delete 
 * the content of a node if needed.
 * 
 * Returns the new list or NULL if the allocation fails.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a 
 * node if needed.
 * @return t_list* 
 */
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temporary;

	temporary = lst;
	while (temporary != NULL)
	{
		f(temporary->content);
		temporary = temporary->next;
	}
}