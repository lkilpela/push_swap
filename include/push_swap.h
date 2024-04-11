/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 09:10:10 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "./lib/libft/include/libft.h"

enum	e_error
{
	ERR_NONE,
	ERR_NOT_ENOUGH_ARG,
	ERR_NOT_INT,
	ERR_INVALID_ARG,
	ERR_EMPTY_ARG,
	ERR_DUPLICATE
};

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