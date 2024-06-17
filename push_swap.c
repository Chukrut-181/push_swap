/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:00 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/17 12:49:42 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_create_stack_a(t_stack **a, int *num_str, int argc)
{
	t_stack	*new_node;

	while (--argc > 0)
	{
		new_node = ft_lstnew(num_str);
		ft_lstadd_back(a, new_node);
		num_str++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*aux;
	int		*num_str;

	if (argc < 2)
		return (0);
	ft_evaluate_quality(argv);
	num_str = ft_convert_to_int(argc, argv);
	a = NULL;
	ft_create_stack_a(&a, num_str, argc);
	free (num_str);
	ft_swap(&a);
	while (a)
	{
		printf("%i\n", a->number);
		aux = a;
		a = a->next;
		free(aux);
	}
	return (0);
}
