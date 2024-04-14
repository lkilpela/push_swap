/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:55:08 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 17:54:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the positions of the top node and second node of a stack
static void	swap(t_stack_node **head)
{
	t_stack_node *temp;

	if (!(*head) || !(*head)->next)
		return ;
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = temp;
	(*head)->next = temp;
	temp->prev = *head;
	(*head)->prev = NULL;
}

//Swap the first two nodes of stack `a` and print the instruction
void	sa(t_stack_node	**a, bool print)
{
    swap(a);
	if (!print)
		ft_printf("sa\n");
}

//Swap the first two nodes of stack `b` and print the instruction
void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

//Stimutaneously swap the first two nodes of the stack and print the instruction
void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
