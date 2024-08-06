/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:42:09 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/06 09:44:05 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv, bool argc_is_2)
{
	free_stack(a);
	if (argc_is_2)
		free_argv(argv);
	write(2, "Error\n", 6);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
	{
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
	}
	create_stack(&a, argv, argc == 2);
}
