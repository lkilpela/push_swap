/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:13:11 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 10:55:29 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			closest_bigger_number;

	if (!a)
		return ;
	while (b)
	{
		closest_bigger_number = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr
				&& current_a->nbr < closest_bigger_number)
			{
				closest_bigger_number = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_bigger_number == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	prepare_nodes_b(t_stack_node *a, t_stack_node *b)
{
	mark_median(a);
	mark_median(b);
	set_target_b(a, b);
}
