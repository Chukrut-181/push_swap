/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:00 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/29 11:46:00 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack_node **a)
{
	t_stack_node	*aux;

	aux = NULL;
	while (*a)
	{
		aux = (*a);
		(*a) = (*a)->next;
		free (aux);
	}
}

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (-1);
}

int	ft_is_ordered(t_stack_node **a)
{
	t_stack_node	*ref;

	ref = (*a);
	while (ref && ref->next && ref->number < ref->next->number)
	{
		ref = ref->next;
	}
	if (!ref->next)
	{
		ft_free_stack(a);
		return (1);
	}
	return (0);
}

/* ft_create_stack_a converts from the already evaluated int string into
a linked list, which is the initial stack a. */
void	ft_create_stack_a(t_stack_node **a, int *num_str, int argc)
{
	t_stack_node	*new_node;
	int		*aux;

	aux = num_str;
	while (--argc > 0)
	{
		new_node = ft_lstnew(aux);
		ft_lstadd_back(a, new_node);
		aux++;
	}
	free(num_str);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*aux;
	int		*num_str;

	if (argc < 2)
		return (0);
	ft_evaluate_quality(argv);
	num_str = ft_convert_to_int(argc, argv);
	a = NULL;
	b = NULL;
	ft_create_stack_a(&a, num_str, argc);
	if (ft_is_ordered(&a))
		return (0);
	if (argc == 3)
		solve_for_two(&a);
	if (argc == 4)
		solve_for_three(&a);
	while (a || b)
	{
		if (a)
			printf("%i  ", a->number);
		else
			printf("   ");
		if (b)
			printf("%i\n", b->number);
		else
			printf(" \n");
		if (a)
		{
			aux = a;
			a = a->next;
			free(aux);
		}
		if (b)
		{
			aux = b;
			b = b->next;
			free (aux);
		}
	}
	printf("-  -\n");
	printf("A  B\n\n");
	return (0);
}
