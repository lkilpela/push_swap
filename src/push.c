/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:20:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 12:10:35 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculates minimum number of rotations required to move an element to top
// Stack size is less than 2: no rotations are needed.
// If the element is in the first half of the stack: closer to top 
//	- quicker to rotate the stack upwards (rotate top nbr to bottom)
// If the element is in the second half of the stack: closer to the bottom
//	- quicker to rotate the stack downwards (rotate bottom nbr to top)
int	calculate_min_rotations(t_stack *s, int i)
{
	int	median;

	median = s->size / 2;
	if (s->size < 2)
		return (0);
	if (i < median)
		return (i);
	return (s->size - i);
}

// Moves a value from stack a to stack b and prints the operations
static void	push_a_to_b(t_stack *a, int index, t_stack *b)
{
	int	a_moves;
	int	b_index;
	int	b_moves;

	a_moves = calculate_min_rotations(a, index);
	b_index = find_insert_location(b, a->array[index]);
	b_moves = calculate_min_rotations(b, b_index);
	rotate_stack("a", a, index, a_moves);
	rotate_stack("b", b, b_index, b_moves);
	ft_printf("pb\n");
	push_to_top(b, remove_top(a));
}

// calculates the minimum number of operations needed to move an element 
// from stack a to stack b while maintaining the sorted order of the stacks.
static int	calculate_ops(t_stack *a, int i, t_stack *b)
{
	int	min_op;
	int	location;

	min_op = calculate_min_rotations(a, i);
	location = find_insert_location(b, a->array[i]);
	min_op += calculate_min_rotations(b, location);
	return (min_op + 1);
}

// calculates the cost of moving each item from stack a to stack b, 
// finds the item with the lowest cost, moves that item, 
// and prints the operations performed during this process.
void	do_optimal_push(t_stack *a, t_stack *b)
{
	int	*moves;
	int	i;

	i = 0;
	moves = malloc(a->size * sizeof(int));
	if (moves == NULL)
		exit(1);
	while (i != a->size)
	{
		moves[i] = calculate_ops(a, i, b);
		i++;
	}
	i = find_smallest(moves, a->size);
	push_a_to_b(a, i, b);
	free(moves);
}

/*
// moves a value from stack a to stack b and prints the operations performed 
	during this process
static void	push_a_to_b(t_stack *a, int index, t_stack *b)
{
	int	a_moves;
	int	b_index;
	int b_moves;

	// calculates minimum number of rotations needed to bring element 
		at the given index in stack a to top
	a_moves = calculate_min_rotations(a, index);
	// finds the location in stack b where the element should be inserted 
		to maintain the sorted order.
	b_index = find_insert_location(b, a->array[index]);
	//calculates the minimum number of rotations needed to bring the element 
		at the location b_index in stack b to the top
	b_moves = calculate_min_rotations(b, b_index);
	// rotates stack a a_moves times and prints the rotation operations.
	rotate_stack("a", a, index, a_moves);
	// rotates stack b b_moves times and prints the rotation operations.
	rotate_stack("b", b, b_index, b_moves);
	ft_printf("pb\n");// an element is being pushed from stack a to stack b.
	//removes the top element from stack a and appends it to the top of stack b
	push_to_top(b, remove_top(a));
}

// calculates the minimum number of operations needed to move an element 
// from stack a to stack b while maintaining the sorted order of the stacks.
static int	calculate_ops(t_stack *a, int i, t_stack *b)
{
	int	min_op;
	int	location;
	//calculates the minimum number of rotations needed to bring the element 
	//at the given i in stack a to the top
	min_op = calculate_min_rotations(a, i);
	//finds the location in stack b where the element should be inserted to 
		maintain the sorted order
	location = find_insert_location(b, a->array[i]);
	//calculates the minimum number of rotations needed to bring the element at 
	//the location in stack b to the top.
	min_op += calculate_min_rotations(b, location);
	// adding 1 is to account for the operation of actually moving the element 
		from stack a to stack b.
	return (min_op + 1);
}

// calculates the cost of moving each item from stack a to stack b, 
// finds the item with the lowest cost, moves that item, 
// and prints the operations performed during this process.
void	do_optimal_push(t_stack *a, t_stack *b)
{
	int	*moves;
	int	i;

	i = 0;
	moves = malloc(a->size * sizeof(int));
	while (i != a->size)
	{
		moves[i] = calculate_ops(a, i, b);//calculates the cost of moving the 
											item at i i from stack a to stack b
		i++;
	}
	i = find_smallest(moves, a->size);// finds the i of the item with the 
										lowest cost in the cost array.
	push_a_to_b(a, i, b);//moves the item at i i from stack a to stack b 
							and prints the operations 
	free(moves);
}

*/