/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:00 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/15 17:48:34 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **a)
{
	t_stack	*aux;

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

int	ft_is_ordered(t_stack **a)
{
	t_stack	*ref;

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

void	ft_create_stack_a(t_stack **a, int *num_str, int argc)
{
	t_stack	*new_node;
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
	t_stack	*a;
	t_stack	*b;
	t_stack	*aux;
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
