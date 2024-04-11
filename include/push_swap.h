/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 08:50:26 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include "./lib/libft/include/libft.h"

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