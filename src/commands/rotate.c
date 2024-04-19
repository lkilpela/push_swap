/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:54:57 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 12:00:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move the top node of a stack to the bottom
static void	rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!*head || !(*head)->next)
		return ;
	last_node = stack_last(*head);
	last_node->prev->next = NULL; // Detach last node from end of list
	last_node->next = *head;
	(*head)->prev = last_node;
	(*head) = last_node;
	(*head)->prev = NULL;
}

 // Rotate the top `a` node to the bottom of the stack, and print the instruction
void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

 //Rotate the top `b` node to the bottom of the stack, and print the instruction
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

 //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
