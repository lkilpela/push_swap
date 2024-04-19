/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:34:59 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 14:16:24 by lkilpela         ###   ########.fr       */
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
			if (ft_atol(&str[i]) == ft_atol(&str[j]))
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

static void	append_node(t_stack_node **a, char *str)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = create_node(str);
	if ((*a) != NULL)
	{
		last_node = stack_last(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	else
		*a = new_node;
}
void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		error_if(is_not_int(argv[i]));
		nbr = ft_atol(argv[i]);
		error_if(nbr > INT_MAX || nbr < INT_MIN);
		error_if(is_duplicate(argv[i], ft_strlen(argv[i])));
		append_node(a, argv[i]);
		i++;
	}
	free_ptrs(argv);
}
