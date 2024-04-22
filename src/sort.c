/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:28:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 10:59:35 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int i;

	i = 0;
	//if (s->size < 2)
		//return (1);
	while (i < s->size - 1)
	{
		if (s->array[i] > s->array[i + 1])
			return (0);
		i++;
	}
	return (1);    
}

void	sort(t_stack *a)
{
	t_stack b;

	if (!is_sorted(a))
	{
		init_stack(&b);
		if (a->size == 2)
			swap(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size == 5)
			sort_five(a, &b);
		else
		{
			while (a->size > 0)
				do_optimal_push(a, &b);
			rotate_to_sort_stack("b", &b);
			while (b.size > 0)
			{
				push_to_top(a, remove_top(&b));
				ft_printf("pa\n");
			}
		}
		free_stack(&b);
	}
}
