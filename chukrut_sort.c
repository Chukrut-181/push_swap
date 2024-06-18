/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chukrut_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:34:09 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/18 17:41:17 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chukrut_sort(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if((*a)->next && (*a)->number > (*a)->next->number)
		{
			write(1, "sa\n", 3);
			ft_swap(a);
		}
		write(1, "pb\n", 3);
		ft_push(a, b);
		i++;
	}
}