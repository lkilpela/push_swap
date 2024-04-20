/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:48:07 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 23:54:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i != s->size - 1)
	{
		j = i;
		while (j != s->size)
		{
			if (i != j && s->str[i] == s->str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_not_int(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (true);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	build_stack(t_stack *s, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (*argv)
	{
		push_to_stack_back(s, ft_atol(*argv));
		error_if(is_duplicate(*argv));
		argv++;
	}
	
}