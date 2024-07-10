/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:27:08 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/10 18:37:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	exec_same_rots(t_stack **a, t_stack **b, int roto, int rotd)
{
	while (roto > 0 && rotd > 0)
	{
		ft_rotate(a);
		ft_rotate(b);
		write(1, "rr\n", 3);
		roto--;
		rotd--;
	}
	while (roto > 0)
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
		roto--;
	}
	while (rotd > 0)
	{
		ft_rotate(b);
		write(1, "rb\n", 3);
		rotd--;
	}
}

void	exec_same_r_rots(t_stack **a, t_stack **b, int roto, int rotd)
{
	while (roto < 0 && rotd < 0)
	{
		ft_r_rotate(a);
		ft_r_rotate(b);
		write(1, "rrr\n", 4);
		roto++;
		rotd++;
	}
	while (roto < 0)
	{
		ft_r_rotate(a);
		write(1, "rra\n", 4);
		roto++;
	}
	while (rotd < 0)
	{
		ft_r_rotate(b);
		write(1, "rrb\n", 4);
		rotd++;
	}
}

void	exec_opposite_rots(t_stack **a, t_stack **b, int roto, int rotd)
{
	while (roto > 0)
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
		roto--;
	}
	while (roto < 0)
	{
		ft_r_rotate(a);
		write(1, "rra\n", 4);
		roto++;
	}
	while (rotd > 0)
	{
		ft_rotate(b);
		write(1, "rb\n", 3);
		rotd--;
	}
	while (rotd < 0)
	{
		ft_r_rotate(b);
		write(1, "rrb\n", 4);
		rotd++;
	}
}
