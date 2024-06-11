/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:29:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/11 10:36:45 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct l_list
{
	struct l_list	*previous;
	int				number;
	struct l_list	*next;
}	stack;

int		main(int argc, char **argv);
void	ft_create_stack_a(stack **a, char **argv);
stack	*ft_lstnew(char *content);
void	ft_lstadd_back(stack **lst, stack *new);
stack	*ft_lstlast(stack *lst);

int	ft_atoi(const char *str);

#endif