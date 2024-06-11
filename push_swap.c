/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:00 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/11 15:13:43 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack_a(t_stack **a, char **argv, int argc)
{
	int		i;
	t_stack	*new_node;

	i = 1;
	while (i <= argc - 1)
	{
		new_node = ft_lstnew(argv[i]);
		ft_lstadd_back(a, new_node);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*aux;

	if (argc < 2)
		return (0);
	a = NULL;
	ft_create_stack_a(&a, argv, argc);
	while (a)
	{
		printf("%i\n", a->number);
		aux = a;
		a = a->next;
		free(aux);
	}
	return (0);
}
