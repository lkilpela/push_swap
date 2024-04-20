/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:36:07 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Search a stack and returns the node with the biggest number
t_stack	*find_max(t_stack *head)
{
	long			max;
	t_stack	*max_node;

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
t_stack	*find_min(t_stack *head)
{
	long			min;
	t_stack	*min_node;

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

int	stack_size(t_stack *head)
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

t_stack	*stack_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
