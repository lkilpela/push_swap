/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/16 22:50:05 by lkilpela         ###   ########.fr       */
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

// Function to create a new node from a string and add it to the stack
t_stack_node *create_node(const char *str)
{
	int	nbr;
	t_stack_node *new_node;

	nbr = ft_atoi(str);
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

void	init_node_a(t_push_swap *ps)
{
	int				i;
	t_stack_node	*new_node;

	i = 1;
	while (i < ps->argc)
	{
		if (validate_argument(ps->argv[i]))
		{
			new_node = create_node(ps->argv[i]);// Create a new node from the argument
			if (!new_node)
				error(ERR_MEMORY);
			new_node->next = ps->a; // Add the new node to the stack. The next pointer of the new node is set to the current top of the stack
			if (ps->a)// If the stack is not empty, the previous pointer of the current top node is set to the new node
				ps->a->prev = new_node;
			ps->a = new_node; // The top of the stack is updated to be the new node
		}
		i++;
	}
}
