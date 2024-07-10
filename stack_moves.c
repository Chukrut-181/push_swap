/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:35:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/10 17:27:40 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a)
{
	int	aux;

	aux = (*a)->next->number;
	(*a)->next->number = (*a)->number;
	(*a)->number = aux;
}

void	ft_push(t_stack **give, t_stack **take)
{
	t_stack	*push;

	push = *give;
	*give = (*give)->next;
	if (*give)
	{
		(*give)->previous->next = NULL;
		(*give)->previous = NULL;
	}
	ft_lstadd_front(take, push);
}
