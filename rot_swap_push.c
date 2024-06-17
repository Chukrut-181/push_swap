/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:35:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/17 11:18:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **a)
{
	int aux;

	aux = (*a)->next->number;
	(*a)->next->number = (*a)->number;
	(*a)->number = aux;
}

void	ft_rotate(t_stack **a)
{
	t_stack	*curr_last;
	t_stack	*to_be_last;

	curr_last = ft_lstlast(*a);
	to_be_last = (*a);
	*a = (*a)->next;
	(*a)->previous = NULL;
	to_be_last->next = NULL;
	curr_last->next = to_be_last;
	to_be_last->previous = curr_last;
}

void	ft_r_rotate(t_stack **a)
{
	t_stack	*last;

	last = ft_lstlast(*a);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = (*a);
	(*a)-> previous = last;
	*a = last;
}
