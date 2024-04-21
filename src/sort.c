/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:28:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 10:04:03 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int i;

	i = 0;
	if (s->size < 2)
		return (1);
	while (i < s->size - 1)
	{
		if (s->array[i] > s->array[i + 1])
			return (0);
		i++;
	}
	return (1);    
}

void	sort_three(t_stack *s)
{
	if (s->size < 2)
		return ;
	if (s->array[0] > s->array[1])
	{
		swap(s);
		ft_printf("sa\n");
	}
	if (s->size == 3)
	{
		if (s->array[1] > s->array[2])
		{
			reverse_rotate(s);
			ft_printf("rra\n");
		}
		
	}
}

void	sort(t_stack *s)
{
	t_stack b;

	if (!is_sorted(s))
	{
		init_stack(&b);
		while (s->size > 0)
		{
			
		}
	}
}