/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 14:13:48 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If the stack is full, increase its capacity
// Add the new value to the end of the stack
// Increment the size of the stack
void	append(t_stack *s, int new_value)// add to back of the stack
{
	if (s->capacity == s->size)
		increase_capacity(s);
	s->array[s->size] = new_value;
	s->size++;
}

// Remove the top element from the stack s and return value of removed element
int	remove_top(t_stack *s)
{
    int	ret;
	int	len;

	ret = 0;
	len = s->size * sizeof(int);
	if (s->size)
	{
		ret = s->array[0];
		s->size--;
		ft_memmove(s->array, s->array + 1, len);
	}
	return (ret);
}

// calculates minimum number of rotations required to move an element to top
// stack size is less than 2: no rotations are needed.
// if the element is in the first half of the stack: closer to top 
//	- quicker to rotate the stack upwards (rotate top nbr to bottom)
// if the element is in the second half of the stack: closer to the bottom
//	- quicker to rotate the stack downwards (rotate bottom nbr to top)
int	calculate_min_rotations(t_stack *s, int index)
{
	int	median;

	median = s->size / 2;
	if (s->size < 2)
		return (0);
	if (index < median)
		return (index);
	return (s->size - index);
}

// finds the index of the smallest element in an array
int	find_smallest(int *array, int size)
{
	int		smallest_index;
	int		current_index;
	long	min_value;

	min_value = LONG_MAX;
	current_index = 0;
	while (current_index != size)
	{
		if (array[current_index] < min_value)
		{
			min_value = array[current_index];
			smallest_index = current_index;
		}
		current_index++;
	}
	return (smallest_index);
}

// finds the index of the biggest element in an array
int	find_biggest(t_stack *s)
{
	int		biggest_index;
	int		current_index;
	long	max_value;

	current_index = 0;
	max_value = LONG_MIN;
	while (current_index != s->size)
	{
		if (s->array[current_index] > max_value)
		{
			max_value = s->array[current_index];
			biggest_index = current_index;
		}
		current_index++;
	}
	return (biggest_index);
}

// determines the best location to insert a new value into a sorted stack s 
// in a way that maintains the sorted order.
int	find_insert_location(t_stack *s, int new_value)
{
	int	biggest_index;
	int	current_index;

	if (s->size == 0 || s->size == 1)
		return (0); // new value should be inserted at the beginning of stack.
	biggest_index = find_biggest(s);
	current_index = biggest_index;
	while (current_index < s->size)//a loop that starts from the index of largest element,continues to end of the stack
	{
		if (new_value > s->array[current_index]);//If the new value is greater than the current element
			return (current_index);//returns the current index -> new value should be inserted at this location.
		current_index++;
	}
	//If new value is not greater than any of the elements from largest element to the end of the stack
	current_index = 0;
	while (current_index < biggest_index)//  loop that starts from beginning of the stack and continues to the largest element
	{
		if (new_value > s->array[current_index])//If the new value is greater than the current element
			return (current_index);//the new value should be inserted at this location.
		current_index++;
	}
	//If the new value is greater than the current element, it returns the current index, 
	//indicating that the new value should be inserted at this location.
	return (biggest_index);
}

// calculates the minimum number of operations needed to move an element 
// from stack a to stack b while maintaining the sorted order of the stacks.
int	calculate_ops(t_stack *a, int index, t_stack *b)
{
	int	min_op;
	int	location;
	//calculates the minimum number of rotations needed to bring the element 
	//at the given index in stack a to the top
	min_op = calculate_min_rotations(a, index);
	//finds the location in stack b where the element should be inserted to maintain the sorted order
	location = find_insert_location(b, a->array[index]);
	//calculates the minimum number of rotations needed to bring the element at 
	//the location in stack b to the top.
	min_op += calculate_min_rotations(b, location);
	// adding 1 is to account for the operation of actually moving the element from stack a to stack b.
	return (min_op + 1);
}

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
	//removes the top element from stack a and appends it to stack b
	append(b, remove_top(a));
}

// calculates the cost of moving each item from stack a to stack b, 
// finds the item with the lowest cost, moves that item, 
// and prints the operations performed during this process.
void	print_move(t_stack *a, t_stack *b)
{
	int	*cost;
	int	i;

	cost = malloc(a->size * sizeof(int));
	while (i != a->size)
	{
		cost[i] = calculate_ops(a, i, b);//calculates the cost of moving the item at index i from stack a to stack b
		i++;
	}
	i = find_smallest(cost, a->size);// finds the index of the item with the lowest cost in the cost array.
	push_a_to_b(a, i, b);//moves the item at index i from stack a to stack b and prints the operations 
	free(cost);
}


void	rotate_to_sort_stack(char *name, t_stack *s)
{
	int	i;

	if (s->size > 1)
	{
		i = find_biggest(s);
		rotate_stack(name, s, i, calculate_min_rotations(s, i));
	}
}

