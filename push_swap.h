/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:29:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/11 15:12:48 by igchurru         ###   ########.fr       */
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
}	t_stack;

int		main(int argc, char **argv);
void	ft_create_stack_a(t_stack **a, char **argv, int argc);
t_stack	*ft_lstnew(char *content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);

int		ft_atoi(const char *str);

#endif