/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:51:11 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/29 11:46:00 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_lstnew(int *content)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		return (NULL);
	new_node->previous = NULL;
	new_node->number = *content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_stack_node **a, t_stack_node *new)
{
	t_stack_node	*last;

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

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		new->next = *lst;
		(*lst)->previous = new;
		new->previous = NULL;
		*lst = new;
	}
}

t_stack_node	*ft_lstlast(t_stack_node *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next != NULL)
		a = a->next;
	return (a);
}

int	stacksize(t_stack_node *lst)
{
	int		stack_size;
	t_stack_node	*ref;

	stack_size = 0;
	ref = lst;
	while (ref)
	{
		stack_size++;
		ref = ref->next;
	}
	return (stack_size);
}
