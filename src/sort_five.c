/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:35:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 10:21:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Identify the two smallest numbers in the stack.
// Move these two numbers to the top of the stack using the appropriate operations (ra, rra, sa).
// Push these two numbers onto stack B (pb).
void	rotate_smallest_to_top(t_stack *a, t_stack *b)
{
	int	smallest_i;
	int	a_moves;

	smallest_i = find_smallest(a->array, a->size);
	a_moves = calculate_min_rotations(a, smallest_i);
	rotate_stack("a", a, smallest_i, a_moves);
	push_to_top(b, remove_top(a));
	ft_printf("pb\n");
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
