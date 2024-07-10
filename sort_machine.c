/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_machine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:00:47 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/10 18:39:44 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	determine_rotation_sequence(t_stack **a, t_stack **b, t_stack *optimal)
{
	int	seq_orig;
	int	seq_dest;

	seq_orig = rots_in_origin(a, optimal->number);
	seq_dest = rots_in_dest(b, optimal->number);
	if (seq_orig >= 0 && seq_dest >= 0)
	{
		exec_same_rots(a, b, seq_orig, seq_dest);
	}
	else if (seq_orig < 0 && seq_dest < 0)
	{
		exec_same_r_rots(a, b, seq_orig, seq_dest);
	}
	else
	{
		exec_opposite_rots(a, b, seq_orig, seq_dest);
	}
}

int	rots_in_origin(t_stack **a, int number)
{
	int		len;
	int		rot_orig;
	t_stack	*ref;

	ref = *a;
	len = stacksize(ref);
	rot_orig = 0;
	while (ref)
	{
		if (ref->number == number)
		{
			if (rot_orig <= len / 2)
				return (rot_orig);
			return (rot_orig - len);
		}
		rot_orig++;
		ref = ref->next;
	}
	return (0);
}

int	rots_in_dest(t_stack **b, int number)
{
	int		len;
	int		rot_dest;
	t_stack	*ref;

	ref = *b;
	len = stacksize(*b);
	rot_dest = 0;
	while (ref)
	{
		if (number > ref->number && number < ft_lstlast(ref)->number)
		{
			if (rot_dest <= len / 2)
				return (rot_dest);
			return (rot_dest - len);
		}
		rot_dest++;
		ref = ref->next;
	}
	return (0);
}

void	find_optimal(t_stack **a, t_stack **b)
{
	int		rot_orig;
	int		rot_dest;
	int		count;
	int		lowest;
	t_stack	*optimal;

	lowest = 2147483647;
	while (*a)
	{
		rot_orig = rots_in_origin(a, (*a)->number);
		if (rot_orig < 0)
			count = -rot_orig;
		else
			count = rot_orig;
		rot_dest = rots_in_dest(b, (*a)->number);
		if (rot_dest < 0)
			count += -rot_dest;
		else
			count += rot_dest;
		if (count < lowest)
			optimal = (*a);
		(*a) = (*a)->next;
	}
	determine_rotation_sequence(a, b, optimal);
}
