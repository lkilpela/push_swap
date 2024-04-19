/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:22:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 11:53:47 by lkilpela         ###   ########.fr       */
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

void	prep_push_a(t_stack_node **head, t_stack_node *cheapest_node)
{
	while (*head != cheapest_node)
	{
		if (cheapest_node->above_median)
			ra(head, false);
		else
			rra(head, false);
	}
}

void	prep_push_b(t_stack_node **head, t_stack_node *cheapest_node)
{
	while (*head != cheapest_node)
	{
		if (cheapest_node->above_median)
			rb(head, false);
		else
			rrb(head, false);
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
