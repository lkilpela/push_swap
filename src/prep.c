/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 11:57:20 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// If the stack is full, increase its capacity
// Add the new value to the end of the stack
// Increment the size of the stack
void	append(t_stack *s, int nbr)// add to back of the stack
{
	if (s->capacity == s->size)
		increase_capacity(s);
	s->array[s->size] = nbr;
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
int	min_rotation(t_stack *s, int index)
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
