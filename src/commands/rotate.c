/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:54:57 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 12:04:54 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move the top node of a stack to the bottom
// line 23: Detach last node from end of list
static void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!*head || !(*head)->next)
		return ;
	last_node = stack_last(*head);
	last_node->prev->next = NULL;
	last_node->next = *head;
	(*head)->prev = last_node;
	(*head) = last_node;
	(*head)->prev = NULL;
}

 // Rotate the top `a` node to the bottom of the stack & print intruction
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

 //Rotate the top `b` node to the bottom of the stack & print instruction
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

 //Rotate both the top `a` and `b` nodes to the bottom of the stack & print ins.
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
