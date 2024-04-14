/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 21:23:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort a stack with three nodes
void	sort_three(t_stack_node **head)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*head);
	if (biggest_node == *head)
		ra(head, false);
	else if ((*head)->next == biggest_node)
		rra(head, false);
	if ((*head)->nbr > (*head)->next->nbr)
		sa(head, false);
}
