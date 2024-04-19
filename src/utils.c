/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 10:23:24 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Search a stack and returns the node with the biggest number
t_stack_node	*find_max(t_stack_node *head)
{
	long			max;
	t_stack_node	*max_node;

	if (!head)
		return (NULL);
	max = LONG_MIN;
	max_node = NULL;
	while (head)
	{
		if (head->nbr > max)
		{
			max = head->nbr;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

// Search a stack and returns the node with the smallest number
t_stack_node	*find_min(t_stack_node *head)
{
	long			min;
	t_stack_node	*min_node;

	if (!head)
		return (NULL);
	min = LONG_MAX;
	while (head)
	{
		if (head->nbr < min)
		{
			min = head->nbr;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

int	stack_size(t_stack_node *head)
{
	int	i;

	i = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack_node	*stack_last(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
