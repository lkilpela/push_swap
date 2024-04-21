/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:32:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 10:01:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate the elements of the stack s upwards
// s->array + 1: destination - copy starts from second element of the array.
// s->array: source - copy starts from first element of the array.
// len: size of the stack in bytes excluding the last element.
// sets first element (s->array[0]) to nbr - value of the previously last element.
void	reverse_rotate(t_stack *s)
{
	int	nbr;
	int	len;

	len = (s->size - 1) * sizeof(int);
	if (s->size)
	{
		nbr = s->array[s->size - 1]; 
		ft_memmove(s->array + 1, s->array, len);
		s->array[0] = nbr;
	}
}

void	rotate(t_stack *s)
{
	int	nbr;
	int	len;

	len = (s->size - 1) * sizeof(int);
	if (s->size)
	{
		nbr = s->array[0]; 
		ft_memmove(s->array, s->array + 1, len);
		s->array[s->size - 1] = nbr;
	}
}

void	swap(t_stack *s)
{
	int	nbr;

	if (s->size > 1)
	{
		nbr = s->array[0];
		s->array[0] = s->array[1];
		s->array[1] = nbr;
	}
}

