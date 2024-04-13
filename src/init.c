/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/13 20:34:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_push_swap(int argc, char **argv, t_push_swap *ps)
{
	ps->argc = argc;
	ps->argv = argv;
	ps->arg = NULL;
	ps->tab = NULL;
}

/*void	init_stack(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}*/

void	init_node_a(int nbr, t_stack_node *a)
{
	a->nbr = nbr;
	a->index = -1;
	a->pust_cost = -1;
	a->above_median = false;
	a->cheapest = false;
	a->target_node = NULL;
	a->next = NULL;
	a->prev = NULL;
}

void	init_node_b(int nbr, t_stack_node *b)
{
	b->nbr = nbr;
	b->index = -1;
	b->pust_cost = -1;
	b->above_median = false;
	b->cheapest = false;
	b->target_node = NULL;
	b->next = NULL;
	b->prev = NULL;
}