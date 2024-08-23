/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:13 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/23 09:13:14 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Simply compare two numbers and return the bigger one. */
int	find_higher(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

/* This function works as a logic "and" gate. If both values are true or false
returns true. In they are different returns false. */
bool	both_in_same_half(t_stack_node *b)
{
	if (b->above_middle == b->target_node->above_middle)
		return (true);
	else
		return (false);
}

/* Scans a stack looking for the "is_cheapest" flag. Returns a pointer to
the cheapest node. */
t_stack_node	*find_cheapest(t_stack_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->is_cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
