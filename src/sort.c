/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:28:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 16:24:09 by lkilpela         ###   ########.fr       */
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

void print_stack(t_stack *s) // need to remove later
{
	fprintf(stderr, "---\n");
	for(int i = 0; i < s->size; ++i) {
		fprintf(stderr, "%d\n", s->array[i]);
	}
	fprintf(stderr, "---\n");
}

void	sort(t_stack *s)
{
	t_stack b;

	print_stack(s);//need to remove later
	if (!is_sorted(s))
	{
		init_stack(&b);
		while (s->size > 0)
		{
			print_move(s, &b);
		}
		rotate_to_sort_stack("b", &b);
		while (b.size > 0)
		{
			push_to_top(s, remove_top(&b));
			ft_printf("pa\n");
		}
		free_stack(&b);
	}
	print_stack(s); //need to remove later
}