/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:40 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/17 09:42:49 by lkilpela         ###   ########.fr       */
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

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*chepeast_node;

	chepeast_node = get_cheapest(*a);
	if (chepeast_node->above_median
		&& chepeast_node->target_node->above_median)
		rotate_both(a, b, chepeast_node);
	else if (!(chepeast_node->above_median)
			&& (!chepeast_node->target_node->above_median))
		reverse_both(a, b, chepeast_node);
	
}

// Check if stack is sorted in ascending order
bool	stack_sorted(t_stack_node *head)
{
	if (!head)
		return (true);
	while (head->next)
	{
		if (head->nbr > head->next->nbr)
			return (false);
		head = head->next;
	}
	return (true);
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = ft_stacksize(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
		pa(b, a, false);
	if (size_a-- > 3 && !stack_sorted(*a))
		pa(b, a, false);
	while (size_a-- > 3 && !stack_sorted(*a))
	{
		prepare_nodes_a(*a, *b);
	}
}