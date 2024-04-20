/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:48:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:36:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_dlstadd_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}

static void push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	ft_dlstadd_front(dst, push_node);
}

// Move the top node from stack b to stack a
void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

// Move the top node from stack a to stack b
void	pb(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
