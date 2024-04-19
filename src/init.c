/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 09:39:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate(char *str, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (true) ;
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_not_int(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (true);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (true);
		str++;
	}
	return (false);
}

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
		error(is_not_int(argv[i]));
		n = ft_atol(argv[i]);
		error(n > INT_MAX || n < INT_MIN);
		error(is_duplicate(argv[i], ft_strlen(argv[i])));
		i++;
	}
}
