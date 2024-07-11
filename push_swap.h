/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:29:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/11 19:07:49 by igchurru         ###   ########.fr       */
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
void	ft_create_stack_a(t_stack **a, int *num_str, int argc);
t_stack	*ft_lstnew(int *content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		stacksize(t_stack *lst);
void	ft_exit(void);
long	ft_atoi(const char *str);
void	ft_evaluate_quality(char **argv);
int		*ft_convert_to_int(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_is_ordered(t_stack **a);
void	ft_free_stack(t_stack **a);
void	ft_swap(t_stack **a);
void	ft_rotate(t_stack **a);
void	ft_r_rotate(t_stack **a);
void	ft_push(t_stack **give, t_stack **take);
void	exec_same_rots(t_stack **a, t_stack **b, int roto, int rotd);
void	exec_same_r_rots(t_stack **a, t_stack **b, int roto, int rotd);
void	exec_opposite_rots(t_stack **a, t_stack **b, int roto, int rotd);

#endif