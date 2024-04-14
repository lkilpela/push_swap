/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:48:34 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 15:01:25 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_dlstadd_front(t_stack_node **lst, t_stack_node *new)
{
	if (new)
	{
		new->next = *lst;
		if (*lst)
			(*lst)->prev = new;
		*lst = new;
	}
}


static void push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node	*push_node;

	if (!*src)
		return;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	ft_dlstadd_front(dst, push_node);
}