/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 17:22:21 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adds a new value to the top of the stack
void	push_to_top(t_stack *s, int new_value)
{
	int	len;

	len = s->size * sizeof(int);
	if (s->capacity == s->size)
		increase_capacity(s);
	ft_memmove(s->array + 1, s->array, len);
	s->array[0] = new_value;
	s->size++;
}

// If the stack is full, increase its capacity
// Add the new value to the end of the stack
// Increment the size of the stack
void	push_to_back(t_stack *s, int new_value)
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

// finds the i of the smallest element in an array
int	find_smallest(int *array, int size)
{
	int		smallest_i;
	int		current_i;
	long	min_value;

	min_value = LONG_MAX;
	current_i = 0;
	while (current_i != size)
	{
		if (array[current_i] < min_value)
		{
			min_value = array[current_i];
			smallest_i = current_i;
		}
		current_i++;
	}
	return (smallest_i);
}

// finds the i of the biggest element in an array
int	find_biggest(t_stack *s)
{
	int		biggest_i;
	int		current_i;
	long	max_value;

	current_i = 0;
	max_value = LONG_MIN;
	while (current_i != s->size)
	{
		if (s->array[current_i] > max_value)
		{
			max_value = s->array[current_i];
			biggest_i = current_i;
		}
		current_i++;
	}
	return (biggest_i);
}

// determines the best location to insert a new value into a sorted stack s 
// in a way that maintains the sorted order.
int	find_insert_location(t_stack *s, int new_value)
{
	int	biggest_i;
	int	current_i;

	if (s->size == 0 || s->size == 1)
		return (0); // new value should be inserted at the beginning of stack.
	biggest_i = find_biggest(s);
	current_i = biggest_i;
	while (current_i < s->size)//a loop that starts from the i of largest element,continues to end of the stack
	{
		if (new_value > s->array[current_i]);//If the new value is greater than the current element
			return (current_i);//returns the current i -> new value should be inserted at this location.
		current_i++;
	}
	//If new value is not greater than any of the elements from largest element to the end of the stack
	current_i = 0;
	while (current_i < biggest_i)//  loop that starts from beginning of the stack and continues to the largest element
	{
		if (new_value > s->array[current_i])//If the new value is greater than the current element
			return (current_i);//the new value should be inserted at this location.
		current_i++;
	}
	//If the new value is greater than the current element, it returns the current i, 
	//indicating that the new value should be inserted at this location.
	return (biggest_i);
}

// calculates the minimum number of operations needed to move an element 
// from stack a to stack b while maintaining the sorted order of the stacks.
int	calculate_ops(t_stack *a, int i, t_stack *b)
{
	int	min_op;
	int	location;
	//calculates the minimum number of rotations needed to bring the element 
	//at the given i in stack a to the top
	min_op = calculate_min_rotations(a, i);
	//finds the location in stack b where the element should be inserted to maintain the sorted order
	location = find_insert_location(b, a->array[i]);
	//calculates the minimum number of rotations needed to bring the element at 
	//the location in stack b to the top.
	min_op += calculate_min_rotations(b, location);
	// adding 1 is to account for the operation of actually moving the element from stack a to stack b.
	return (min_op + 1);
}

// calculates the cost of moving each item from stack a to stack b, 
// finds the item with the lowest cost, moves that item, 
// and prints the operations performed during this process.
void	prep_push(t_stack *a, t_stack *b)
{
	int	*cost;
	int	i;

	cost = malloc(a->size * sizeof(int));
	while (i != a->size)
	{
		cost[i] = calculate_ops(a, i, b);//calculates the cost of moving the item at i i from stack a to stack b
		i++;
	}
	i = find_smallest(cost, a->size);// finds the i of the item with the lowest cost in the cost array.
	push_a_to_b(a, i, b);//moves the item at i i from stack a to stack b and prints the operations 
	free(cost);
}
