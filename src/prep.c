/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:16:56 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 11:41:42 by lkilpela         ###   ########.fr       */
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

