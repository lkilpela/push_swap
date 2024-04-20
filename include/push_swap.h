/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:34:50 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

# include <stdbool.h>
# include <limits.h> // INT_MIN, INT_MAX
# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit
# include <stdio.h>

typedef struct s_stack
{
	int					nbr;// The integer value of the node.
	struct s_stack*prev;// a pointer to the previous t_stack in a 
							//linked list
	struct s_stack	*next;// a pointer to the next t_stack in a 
								//linked list
}				t_stack;

//Handle errors
//int				validate_argument(int argc, char **argv);
void			error_if(bool status);
// argument initiation
//Stack preparation
void			prep_push(t_stack **head, t_stack *cheapest_node,
				char stack_name);
void			min_on_top(t_stack **a);
//Nodes initiation
void			init_stack_a(t_stack **a, char **argv);
void			prepare_nodes_a(t_stack *a, t_stack *b);
void			prepare_nodes_b(t_stack *a, t_stack *b);
//Commands
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **b, t_stack **a, bool print);
void			sa(t_stack	**a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);
//Algorithms
void			sort_three(t_stack **a);
void			sort_stacks(t_stack **a, t_stack **b);
//Utils
t_stack	*find_max(t_stack *head);
t_stack	*find_min(t_stack *head);
bool			stack_sorted(t_stack *head);
int 			stack_size(t_stack *head);
t_stack	*stack_last(t_stack *head);
//Handle memory
void			free_ptrs(char **array);
void			stack_clear(t_stack **head);
#endif