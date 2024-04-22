/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:48:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 11:20:22 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_not_int(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_printf("Error\n");
			exit(1);
		}
		str++;
	}
}

static void	is_duplicate(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i != s->size - 1)
	{
		j = i;
		while (j != s->size)
		{
			if (i != j && s->array[i] == s->array[j])
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

// Add a new value to the top of the stack.
void	push_to_top(t_stack *s, int new_value)
{
	int	len;

	len = s->size * sizeof(int);
	if (s->capacity == s->size)
		increase_capacity(s);
	ft_memmove(s->array + 1, s->array, len);
	s->array[0] = new_value;
	s->size++;
}

// If the stack is full, increase its capacity.
// Add the new value to the end of the stack.
// Increment the size of the stack.
void	push_to_back(t_stack *s, int new_value)
{
	if (s->capacity == s->size)
		increase_capacity(s);
	s->array[s->size] = new_value;
	s->size++;
}

void	build_stack(t_stack *s, char **argv)
{
	long nbr;

	while (*argv)
	{
		is_not_int(*argv);
		nbr = ft_atol(*argv);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		push_to_back(s, nbr);
		argv++;
	}
	is_duplicate(s);
}
