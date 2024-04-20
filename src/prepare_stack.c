/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:22:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 15:29:36 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node	*get_cheapest(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

// rotate a stack until a specific node (cheapest_node) is at the top of stack.
void	prep_push(t_stack_node **head, t_stack_node *node, char stack_name)
{
	t_stack_node *initial_head = *head;

	while ((*head)!= node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ra(head, false);
			else
				rra(head, false);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rb(head, false);
			else
				rrb(head, false);
		}
		// Exit the loop if the stack has been fully rotated
		if (*head == initial_head)
			break;
	}
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
