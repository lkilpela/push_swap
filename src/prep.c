/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 11:20:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Find the i of the smallest element in an array
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
		return (0);
	biggest_i = find_biggest(s);
	current_i = biggest_i;
	while (current_i < s->size)
	{
		if (new_value > s->array[current_i])
			return (current_i);
		current_i++;
	}
	current_i = 0;
	while (current_i < biggest_i)
	{
		if (new_value > s->array[current_i])
			return (current_i);
		current_i++;
	}
	return (biggest_i);
}

/*
if (s->size == 0 || s->size == 1)
	return (0); // new value should be inserted at the beginning of stack.
biggest_i = find_biggest(s);
current_i = biggest_i;
while (current_i < s->size)//a loop that starts from the i of largest element,
							continues to end of the stack
{
	if (new_value > s->array[current_i])//If the new value is greater than 
										the current element
		return (current_i);//returns the current i -> new value should be 
						inserted at this location.
	current_i++;
}
//If new value is not greater than any of the elements from largest element 
to the end of the stack
current_i = 0;
while (current_i < biggest_i)//  loop that starts from beginning of the
							 stack and continues to the largest element
{
	if (new_value > s->array[current_i])//If the new value is greater 
										than the current element
		return (current_i);//the new value should be inserted at this location.
	current_i++;
}
//If the new value is greater than the current element, it returns 
the current i, 
//indicating that the new value should be inserted at this location.
return (biggest_i);
*/