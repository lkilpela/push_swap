/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:48:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 19:19:18 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	build_stack(t_stack *s, char **argv)
{
	while (*argv)
	{
		is_not_int(*argv);
		push_to_back(s, ft_atol(*argv));
		argv++;
	}
	is_duplicate(s);
}