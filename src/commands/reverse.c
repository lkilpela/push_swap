/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:58:16 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 19:30:10 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Move the bottom node of a stack to the top
static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = ft_lstlast(*head);
	last_node->prev->next = NULL; //Disconnect last node from the stack
	last_node->next = *head;
	last_node->prev = NULL;
	*head = last_node;
	last_node->next->prev = last_node;	
}
/*last_node->prev: This is a pointer to the node before the last node. In a 
doubly linked list, each node has a prev pointer that points to the previous 
node.
last_node->prev->next: This is a pointer to the next node of the node before 
the last node. Since the next node of the node before the last node is the last 
node itself, last_node->prev->next effectively refers to the last node.*/

//Rotate the bottom of `a` to the top of the stack and print the instruction
void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

 //Rotate the bottom of `b` to the top of the stack and print the instruction
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

 //Stimultaneously rotate both stacks' bottom nodes to the top of their stacks, halving the cost of instructions
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
