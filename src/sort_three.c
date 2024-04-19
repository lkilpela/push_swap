/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 13:41:44 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort a stack with three nodes
void	sort_three(t_stack_node **a)
{
	t_stack_node	*min_node;
	t_stack_node	*max_node;

	mark_median(*a);
	min_node = find_min(*a);
	max_node = find_max(*a);
	if (min_node == *a)
	{
		rra(a, false);
		sa(a, false);
	}
	else if (max_node == *a)
	{
		ra(a, false);
		if (stack_sorted(*a))
			sa(a, false);
	}
	else
	{
		if(max_node->above_median == true)
			rra(a, false);
		else
			sa(a, false);
	}
}
