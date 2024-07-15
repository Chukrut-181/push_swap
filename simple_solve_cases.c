/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solve_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:43:11 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/15 18:16:54 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_for_two(t_stack **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	solve_for_three(t_stack **a)
{
	if ((*a)->number > (*a)->next->number
		&& (*a)->number > (*a)->next->next->number)
	{
		ft_rotate(a);
		write(1, "ra\n", 3);
	}
	if ((*a)->number > (*a)->next->number)
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
	if ((*a)->next->number > (*a)->next->next->number)
	{
		ft_r_rotate(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->number > (*a)->next->number)
	{
		ft_swap(a);
		write(1, "sa\n", 3);
	}
}
