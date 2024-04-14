/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:40 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 21:44:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate both stacks a and b until the top node of 'a' is the cheapest_node and 
//the top node of 'b' is the target node of the cheapest_node
static void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, false);
	mark_median(*a);
	mark_median(*b);
}

// reverse rotates both stacks until the desired nodes are at the top of their 
// respective stacks. It then refreshes the current position of both stacks.
static void	reverse_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b, false);
	mark_median(*a);
	mark_median(*b);
}

