/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:53:43 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/27 19:11:14 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Takes as a parameter a node and frees the memory of the node’s 
 * content using the function ’del’ given as a parameter and free the node. 
 * The memory of ’next’ must not be freed.
 * 
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temporary;

	temporary = lst;	
	while (temporary != NULL)
	{
		if (temporary->content == &lst)
			del(&temporary);
		temporary = temporary->next;
	}
}
