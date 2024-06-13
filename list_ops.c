/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:51:11 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/13 16:13:10 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int *content)
{
	t_stack	*new_node;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->previous = NULL;
	new_node->number = *content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_stack **a, t_stack *new)
{
	t_stack	*last;

	if (new == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
	new->previous = last;
}

t_stack	*ft_lstlast(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}
