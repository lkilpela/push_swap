/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/13 14:44:41 by lkilpela         ###   ########.fr       */
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

void	init_stack(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}