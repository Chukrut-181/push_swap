/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 09:31:13 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/21 10:17:50 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the two first nodes of a stack. Just pointer games with no return. */
void	swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (!*stack || !stack || stack_size(*stack) == 1)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->previous = second_node;
	first_node->next = second_node->next;
	second_node->previous = NULL;
	second_node->next = first_node;
	if (first_node->next)
		first_node->next->previous = first_node;
	*stack = second_node;
}

/* Executes the SA command and writes "sa". */
void	sa(t_stack_node	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

/* Executes the SB command and writes "sb". */
void	sb(t_stack_node	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

/* Executes the SA and SB commands and writes "sa". */
void	ss(t_stack_node	**a, t_stack_node	**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
