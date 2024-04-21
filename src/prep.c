/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 13:43:26 by lkilpela         ###   ########.fr       */
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

// direction: index is less than half the size of stack -> rotate to bottom
// otherwise -> reverse rotate to top
int	rotate_direction(t_stack *s, int index)
{
	if (index < s->size / 2) // above median
		return (0);
	return (1);
}

void	rotate_stack(char *name, t_stack *a, int i, int moves)
{
	int	j;

	j = 0;
	while (j != moves)
	{
		if (rotate_direction(a, i))
		{
			ft_printf("rr%s\n", name);
			reverse_rotate(a);
		}
		else
		{
			ft_printf("r%s\n", name);
			rotate(a);
		}
		j++;
	}
}
