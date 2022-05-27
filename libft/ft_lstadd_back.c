/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:40:51 by stena-he          #+#    #+#             */
/*   Updated: 2022/05/26 22:06:45 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the end of the list.
 * 
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary;
	t_list	*output;

	temporary = *lst;
	while (temporary != NULL)
	{
		if (temporary->next == NULL)
		{
			output = malloc(sizeof(t_list));
			output->content = new;
			output->next = NULL;
		}	
		temporary = temporary->next;
	}
}