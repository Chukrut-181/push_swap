/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:29:41 by igchurru          #+#    #+#             */
/*   Updated: 2024/08/06 10:33:59 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

/*	T_STACK_NODE STRUCTURE 

The data structure that will form the stack to be sorted.
Contains all necessary metadata to evaluate the optimal move
and sort the initial stack.

*previous		Link to previous node in stack.
number 			Number to be sorted.
curr_index		Current position in the stack.
cost_to_push	Cost to push this particular node from stack b to stack a.
is_cheapest		Flags cheapest node to push.
above_median 	Flags whether this node is nearer to top or bottom of stack.
*target_node	The node on top of which this node must be pushed.
*next			Link to next node in stack.									*/

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

//	MAIN.C
int					main(int argc, char **argv);
void				error_free(t_stack_node **a, char **argv, bool argc_is_2);
void				free_stack(t_stack_node **stack);
void				free_argv(char **argv);

//	FT_SPLIT.C
char				**ft_split(char const *s, char c);
static unsigned int	ft_count_frags(const char *s, char c);
static char			*ft_substr(char const *s, unsigned int start, size_t len);
static size_t		ft_wordlen(const char *word, char c);
static char			**ft_freeall(char **frags, unsigned int k);

//	INITIAL_STACK_CREATION.C
void				create_stack(t_stack_node **a, char **argv, bool argc_is_2);
long				ft_atol(const char *str);
void				add_node(t_stack_node **stack, int number);
t_stack_node		*find_last_node(t_stack_node *node);

//	ARGV_CHECKS.C
bool				check_syntax_error(char *str);
bool				check_interval(long number);
bool				check_repetition(t_stack_node *a, int nbr);

#endif
