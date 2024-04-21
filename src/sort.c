/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:28:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 23:07:47 by lkilpela         ###   ########.fr       */
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

/*void print_stack(t_stack *s) // need to remove later
{
	fprintf(stderr, "---\n");
	for(int i = 0; i < s->size; ++i) {
		fprintf(stderr, "%d\n", s->array[i]);
	}
	fprintf(stderr, "---\n");
}*/

void	sort(t_stack *s)
{
	t_stack b;

	//print_stack(s);//need to remove later
	if (!is_sorted(s))
	{
		init_stack(&b);
		while (s->size > 0)
		{
			do_optimal_push(s, &b);
		}
		rotate_to_sort_stack("b", &b);
		while (b.size > 0)
		{
			push_to_top(s, remove_top(&b));
			ft_printf("pa\n");
		}
		free_stack(&b);
	}
	//print_stack(s); //need to remove later
}