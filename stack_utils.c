/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:44:11 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/22 08:41:06 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack_node *node)
{
	int	size;

	if (!node)
		return (0);
	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

bool	is_sorted(t_stack_node *node)
{
	if (!node)
		return (true);
	while (node->next)
	{
		if (node->number > node->next->number)
			return (false);
		node = node->next;
	}
	return (true);
}
void	solve_for_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	if (!a || !*a || stack_size(*a) != 3)
		return ;
	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->number > (*a)->next->number)
		sa(a);
}
t_stack_node	*find_highest(t_stack_node *node)
{
	int				highest;
	t_stack_node	*highest_node;

	if (!node)
		return (NULL);
	highest = INT_MIN;
	highest_node = NULL;
	while (node)
	{
		if (node->number > highest)
		{
			highest = node->number;
			highest_node = node;
		}
		node = node->next;
	}
	return (highest_node);
}