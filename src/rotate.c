/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:32:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 22:57:52 by lkilpela         ###   ########.fr       */
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

// direction: index is less than half the size of stack -> rotate to bottom
// otherwise -> reverse rotate to top
static int	rotate_direction(t_stack *s, int index)
{
	int	median;

	median = s->size / 2;
	if (index < median) // above median
		return (0);
	return (1);
}

// rotates stack a: a certain number of times in the direction determined by the rotate_dir function
void	rotate_stack(char *name, t_stack *a, int index, int moves)
{
	int	j;

	j = 0;
	while (j != moves)
	{
		if (rotate_direction(a, index))
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

// rotates stack s until it's sorted in ascending order
void	rotate_to_sort_stack(char *name, t_stack *s)
{
	int	i;

	if (s->size > 1)
	{
		i = find_biggest(s);
		//rotates the stack until the largest element is at the top
		rotate_stack(name, s, i, calculate_min_rotations(s, i));
	}
}