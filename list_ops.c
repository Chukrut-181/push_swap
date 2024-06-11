/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:51:11 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/11 11:04:16 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_lstnew(char *content)
{
	stack	*new_node;

	new_node = malloc(sizeof(stack));
	if (new_node == NULL)
		return (NULL);
	new_node->previous = NULL;
    new_node->number = ft_atoi(content);
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(stack **a, stack *new)
{
	stack	*last;

	if (new == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
}

stack	*ft_lstlast(stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

