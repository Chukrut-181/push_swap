/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_machine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:00:47 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/08 18:32:47 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_lowest(t_stack **a)
{
	t_stack	*lowest;
	t_stack	*ref;

	lowest = *a;
	ref = *a;
	while (ref)
	{
		if (ref->next && ref->next->number < lowest->number)
		{
			lowest = ref->next;
		}
		ref = ref->next;
	}
	return (lowest);
}
