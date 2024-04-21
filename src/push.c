/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:20:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 16:21:27 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// moves a value from stack a to stack b and prints the operations performed during this process
void	push_a_to_b(t_stack *a, int index, t_stack *b)
{
	int	a_moves;
	int	b_index;
	int b_moves;

	// calculates minimum number of rotations needed to bring element at the given index in stack a to top
	a_moves = calculate_min_rotations(a, index);
	// finds the location in stack b where the element should be inserted to maintain the sorted order.
	b_index = find_insert_location(b, a->array[index]);
	//calculates the minimum number of rotations needed to bring the element at the location b_index in stack b to the top
	b_moves = calculate_min_rotations(b, b_index);
	// rotates stack a a_moves times and prints the rotation operations.
	rotate_stack("a", a, index, a_moves);
	// rotates stack b b_moves times and prints the rotation operations.
	rotate_stack("b", b, b_index, b_moves);
	ft_printf("pb\n");// an element is being pushed from stack a to stack b.
	//removes the top element from stack a and appends it to the top of stack b
	push_to_top(b, remove_top(a));
}