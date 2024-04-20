/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:40 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:23:59 by lkilpela         ###   ########.fr       */
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
	t_stack_node	*cheapest_node;

	cheapest_node= get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& (!cheapest_node->target_node->above_median))
		reverse_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	//prep_push(b, cheapest_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target_node, 'b');
	pa(a, b, false);
}

// sorts stack `a` if it has more than 3 nodes
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	size_a;
	int	size_b;
	t_stack_node *min_node;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !stack_sorted(*a))
		pa(b, a, false);
	if (size_a-- > 3 && !stack_sorted(*a))
		pa(b, a, false);
	if (size_b == 2 && !stack_sorted(*a))
		rb(b, false);
	pb(b, a, false);
	while (size_a-- > 3 && !stack_sorted(*a))
	{
		//prepare_nodes_a(*a, *b);
		//move_a_to_b(a, b);
		//if the top number is the smallest in stack a, rotate it.
		if ((*a)->nbr == find_min(*a))
			ra(a, false);
	}
	sort_three(a);
	while (*b)
	{
		//prepare_nodes_b(*a, *b);
		//move_b_to_a(a, b);
	}
	mark_median(*a);
	min_on_top(a);
}
