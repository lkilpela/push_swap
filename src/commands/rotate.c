/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:54:57 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 18:07:57 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*temp;

	if (!*head || !(*head)->next)
		return ;
	temp = ft_lstlast(*head);
	temp->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
}

 //Rotate the top `a` node to the bottom of the stack, and print the instruction
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
