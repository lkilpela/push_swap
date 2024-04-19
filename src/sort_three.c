/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:22:55 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 13:58:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort a stack with three nodes
void	sort_three(t_stack_node **a)
{
	t_stack_node	*min_node;
	t_stack_node	*max_node;

	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
	if ((*a)->next->nbr > (*a)->next->next->nbr)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}
