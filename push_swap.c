/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:00 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/11 11:04:04 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack_a(stack **a, char **argv)
{
	int		i;
	stack	*new_node;
	
	i = 1;
	while (argv[i])
	{
		new_node = ft_lstnew(argv[i]);
		ft_lstadd_back(a, new_node);
		i++;
	}
}

int	main(int argc, char  **argv)
{
	stack	*a;
	
	if (argc < 2)
		return (0);
	a = NULL;
	ft_create_stack_a(&a, argv);
	while (a)
	{
		printf("%i\n", a->number);
		a = a->next;
	}
	free(a);
	return (0);
}
