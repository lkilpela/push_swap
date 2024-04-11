/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 11:09:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h> // INT_MIN, INT_MAX
#include <unistd.h> // read, write
#include <stdlib.h> // malloc, free, exit
#include "./lib/libft/include/libft.h"

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
}			t_push_swap;

typedef struct	s_stack_node
{
	int		nbr;
	int		index;
	int		pust_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *target_node;// a pointer to another t_stack_node
	struct s_stack_node *prev;// a pointer to the previous t_stack_node in a linked list
	struct s_stack_node *next;// a pointer to the next t_stack_node in a linked list
}				t_stack_node;

//Handle errors

//Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

# endif