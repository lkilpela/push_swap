/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 12:28:28 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../lib/libft/include/libft.h"

#include <stdbool.h>
#include <limits.h> // INT_MIN, INT_MAX
#include <unistd.h> // read, write
#include <stdlib.h> // malloc, free, exit
#include <stdio.h>


enum	e_error
{
	ERR_NONE,
	ERR_NOT_ENOUGH_ARG,
	ERR_INT_OVERFLOW,
	ERR_FORMAT,
	ERR_EMPTY_ARG,
	ERR_DUPLICATE,
	LAST_ERROR
};

typedef struct s_push_swap
{
	char	**argv;
	char	*arg;
	int		argc;
	char	**tab;
}			t_push_swap;

typedef struct	s_atoi
{
	int	valid;
	int	number;
}				t_atoi;

typedef struct	s_stack_node
{
	int		nbr;// The integer value of the node.
	int		index;//The position of the node in the stack.
	int		push_cost;//The cost of pushing this node onto the stack. This could be used in the sorting algorithm to decide which node to push.
	bool	above_median;//A boolean flag indicating whether the node's value is above the median. This could be used in the sorting algorithm to decide which nodes to push or pop.
	bool	cheapest;//A boolean flag indicating whether this node is the cheapest to push. This could be used in the sorting algorithm to decide which node to push.
	struct s_stack_node *target_node;// a pointer to another t_stack_node. This could be used to keep track of a target node in the sorting algorithm.
	struct s_stack_node *prev;// a pointer to the previous t_stack_node in a linked list
	struct s_stack_node *next;// a pointer to the next t_stack_node in a linked list
}				t_stack_node;

/*typedef struct s_stack
{
	t_stack_node	*top;// a pointer to the top node in the stack. This is used to easily add elements to and remove elements from the top of the stack.
	int				size;//the number of elements in the stack. This is used to quickly check if the stack is empty (size is 0) or to get the number of elements in the stack.
}				t_stack;*/

//Handle errors
int	validate_argument(t_push_swap *ps);
void	error(int e);

// argument initiation
void    init_push_swap(int argc, char **argv, t_push_swap *ps);
//void	init_stack(t_stack *a, t_stack *b);

void	mark_median(t_stack_node *stack);

//Stack preparation
void			prepare_nodes_a(t_stack_node *a, t_stack_node *b);
void			prepare_nodes_b(t_stack_node *a, t_stack_node *b);
t_stack_node    *get_cheapest(t_stack_node *n);

//Nodes initiation
void	init_node_a(int nbr, t_stack_node *a);
void	init_node_b(int nbr, t_stack_node *a);


//Commands

//Algorithms

//Utils
t_atoi			check_atoi_overflow(const char *str);
t_stack_node	*find_max(t_stack_node *stack);

//Handle memory
void    free_ptrs(char **array);

# endif