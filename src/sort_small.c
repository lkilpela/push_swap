/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:35:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 11:06:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//case1 : [2,1,3]->sa->[1,2,3].
//case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].
//case3 : [3,1,2]->ra->[1,2,3].
//case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].
//case5 : [2,3,1]->rra->[1,2,3].
static void	print_rotate(t_stack *s)
{
	rotate(s);
	ft_printf("ra\n");
}

void	sort_three(t_stack *s)
{
	int a = s->array[0];
	int b = s->array[1];
	int c = s->array[2];

	if (a > b && a < c)
		swap(s);
	else if (a > b && b > c)
	{
		swap(s);
		reverse_rotate(s);
		ft_printf("rra\n");
	}
	else if (a > b && b < c)   
		print_rotate(s);
	else if (a < b && b > c && a < c)
	{
		swap(s);
		print_rotate(s);
	}
	else if (a < b && a > c)
	{
		reverse_rotate(s);
		ft_printf("rra\n");
	}
}

//Identify the two smallest numbers in the stack.
// Move these two numbers to the top of the stack using the appropriate operations (ra, rra, sa).
// Push these two numbers onto stack B (pb).
static void	rotate_smallest_to_top(t_stack *a, t_stack *b)
{
	int	smallest_i;
	int	a_moves;

	smallest_i = find_smallest(a->array, a->size);
	a_moves = calculate_min_rotations(a, smallest_i);
	rotate_stack("a", a, smallest_i, a_moves);
	push_to_top(b, remove_top(a));
	ft_printf("pb\n");
}

// Sort three and push 1 number back from stack b to a
void	sort_four(t_stack *a, t_stack *b)
{
	rotate_smallest_to_top(a, b);
	sort_three(a);
	push_to_top(a, remove_top(b));
	ft_printf("pa\n");
}
// Sort three and push 2 numbers back from stack b to a
void	sort_five(t_stack *a, t_stack *b)
{
	rotate_smallest_to_top(a, b);
	rotate_smallest_to_top(a, b);
	sort_three(a);
	push_to_top(a, remove_top(b));
	push_to_top(a, remove_top(b));
	ft_printf("pa\n");
	ft_printf("pa\n");
}
