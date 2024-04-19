/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 20:28:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 10:42:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//assign an index to each node in a stack
//set above_median based on whether the node's index is above/below median index
void	mark_median(t_stack_node *head)
{
	int	i;
	int	median;

	i = 0;
	if (!head)
		return;
	median = stack_size(head) / 2;
	while (head)
	{
		head->index = i;
		if (i < median)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

// Find 'a' node's target in stack 'b'
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_smaller_number;

	while (a)
	{
		closest_smaller_number = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_smaller_number)
			{
				closest_smaller_number = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_smaller_number == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

// Calculate the cost of moving each node in stack a to its target position 
// in stack b
static void	calculate_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = size_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

// Find the node with smallest push_cost & set its 'cheapeast' attribute to true
static void	set_cheapest(t_stack_node *head)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!head)
		return ;
	cheapest_value = LONG_MAX;
	while (head)
	{
		if (head->push_cost < cheapest_value)
		{
			cheapest_value = head->push_cost;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = true;
}

void	prepare_stack_a(t_stack_node *a, t_stack_node *b)
{
	mark_median(a);
	mark_median(b);
	set_target_a(a, b);
	calculate_cost_a(a, b);
	set_cheapest(a);
}
