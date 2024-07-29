/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:29:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/07/29 11:46:20 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAXINT 2147483647
# define MININT -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
	struct s_list	*previous;
	int				number;
	int				curr_index;
	int				cost_to_push;
	bool			is_cheapest;
	bool			above_median;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_stack_node;

int		main(int argc, char **argv);
void	ft_exit(void);

/* ARGUMENT EVALUATION */

long	ft_atoi(const char *str);
void	ft_evaluate_quality(char **argv);
int		*ft_convert_to_int(int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);

/* STACK & LIST OPERATIONS */

void	ft_create_stack_a(t_stack_node **a, int *num_str, int argc);
t_stack_node	*ft_lstnew(int *content);
void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void	ft_free_stack(t_stack_node **a);
int		stacksize(t_stack_node *lst);

/* MOVES */

void	ft_swap(t_stack_node **a);
void	ft_rotate(t_stack_node **a);
void	ft_r_rotate(t_stack_node **a);
void	ft_push(t_stack_node **give, t_stack_node **take);
void	exec_same_rots(t_stack_node **a, t_stack_node **b, int roto, int rotd);
void	exec_same_r_rots(t_stack_node **a, t_stack_node **b, int roto, int rotd);
void	exec_opposite_rots(t_stack_node **a, t_stack_node **b, int roto, int rotd);

/* SORTING ALGOS */

int		ft_is_ordered(t_stack_node **a);
void	solve_for_two(t_stack_node **a);
void	solve_for_three(t_stack_node **a);

#endif