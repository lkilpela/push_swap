/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 22:34:29 by lkilpela         ###   ########.fr       */
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

void	init_node_a(int nbr, t_stack_node *a)
{
	a->nbr = nbr;
	a->index = -1;
	a->push_cost = -1;
	a->above_median = false;
	a->cheapest = false;
	a->target_node = NULL;
	a->next = NULL;
	a->prev = NULL;
}
