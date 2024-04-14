/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 22:44:05 by lkilpela         ###   ########.fr       */
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

void	init_node_a(t_push_swap *ps, char **argv)
{
	int	i = 1;
	while (argv[i])
	{
		ps->a->nbr = ft_atoi(argv[i]);
		ps->a->index = -1;
		ps->a->push_cost = -1;
		ps->a->above_median = false;
		ps->a->cheapest = false;
		ps->a->target_node = NULL;
		ps->a->next = NULL;
		ps->a->prev = NULL;
		i++;
	}
}
