/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 09:02:12 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	init_push_swap(int argc, char **argv, t_push_swap *ps)
{
	ps->argc = argc;
	ps->argv = argv;
	ps->arg = NULL;
	ps->tab = NULL;
	ps->a = NULL;
	ps->b = NULL;
}*/

// Function to create a new node from a string and add it to the stack
t_stack_node	*create_node(const char *str)
{
	int				nbr;
	t_stack_node	*new_node;

	nbr = ft_atol(str);
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->nbr = nbr;
	new_node->index = -1;
	new_node->push_cost = -1;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	n;

	i = 1;
	while (argv[i])
	{
		error(argv[i][0] == '\0');
		n = ft_atol(argv[i]);
		error(n > INT_MAX || n < INT_MIN);
		error(is_duplicate(argv[i]));
		i++;
	}
}
