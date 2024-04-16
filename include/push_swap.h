/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/16 22:49:52 by lkilpela         ###   ########.fr       */
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

enum	e_error
{
	ERR_NONE,
	ERR_NOT_ENOUGH_ARG,
	ERR_INT_OVERFLOW,
	ERR_FORMAT,
	ERR_EMPTY_ARG,
	ERR_DUPLICATE,
	ERR_MEMORY,
	LAST_ERROR
};

typedef struct s_atoi
{
	int	valid;
	int	number;
}				t_atoi;

typedef struct s_stack_node
{
	int					nbr;// The integer value of the node.
	int					index;//The position of the node in the stack.
	int					push_cost;//The cost of pushing this node onto the stack
					//This could be used in the sorting algorithm to decide 
					//which node to push.
	bool				above_median;//A boolean flag indicating whether the 
									//node's value is above the median. 
									//This could be used in the sorting 
									//algorithm to decide which nodes to push 
									//or pop.
	bool				cheapest;//A boolean flag indicating whether this node 
								//is the cheapest to push. This could be used 
								//in the sorting algorithm to decide which node
								//to push.
	struct s_stack_node	*target_node;// a pointer to another t_stack_node.
									//This could be used to keep track of 
									//a target node in the sorting algorithm.
	struct s_stack_node	*prev;// a pointer to the previous t_stack_node in a 
							//linked list
	struct s_stack_node	*next;// a pointer to the next t_stack_node in a 
								//linked list
}				t_stack_node;

typedef struct s_push_swap
{
	char		**argv;
	char		*arg;
	int			argc;
	char		**tab;
	t_stack_node *a;
}			t_push_swap;


//Handle errors
int				validate_argument(t_push_swap *ps);
void			error(int e);
// argument initiation
void			init_push_swap(int argc, char **argv, t_push_swap *ps);
void			mark_median(t_stack_node *n);
//Stack preparation
t_stack_node	*get_cheapest(t_stack_node *head);
void			prep_push(t_stack_node **head, t_stack_node *top,
					char stack_name);
//Nodes initiation
void			init_node_a(t_push_swap *ps);
void			prepare_nodes_a(t_stack_node *a, t_stack_node *b);
void			prepare_nodes_b(t_stack_node *a, t_stack_node *b);
//Commands
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			sa(t_stack_node	**a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
//Algorithms
void			sort_three(t_stack_node **head);
//Utils
t_atoi			check_atoi_overflow(const char *str);
t_stack_node	*find_max(t_stack_node *head);
t_stack_node	*find_min(t_stack_node *head);
bool			stack_sorted(t_stack_node *head);
//Handle memory
void			free_ptrs(char **array);
#endif