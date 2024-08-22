/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:23:13 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/22 12:21:19 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_higher(int n, int m)
{
	if (n > m)
		return (n);
	return (m);
}

bool	both_above_middle(t_stack_node *b)
{
	if (b->above_middle == b->target_node->above_middle)
		return (true);
	else
		return (false);
}

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
