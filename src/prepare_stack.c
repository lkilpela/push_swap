/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:22:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 22:04:12 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	prep_push(t_stack_node **head, t_stack_node *top, char stack_name)
{
	while (*head != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(head, false);
			else
				rra(head, false);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(head, false);
			else
				rrb(head, false);
		}
	}
}
