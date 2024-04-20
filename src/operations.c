/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:32:18 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 23:07:37 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate the elements of the stack s upwards
// s->str + 1: destination - copy starts from second element of the array.
// s->str: source - copy starts from first element of the array.
// len: size of the stack in bytes excluding the last element.
// sets first element (s->str[0]) to nbr - value of the previously last element.
void	reverse_rotate(t_stack *s)
{
	int	nbr;
	int	len;

	len = (s->size - 1) * sizeof(int);
	if (s->size)
	{
		nbr = s->str[s->size - 1]; 
		ft_memmove(s->str + 1, s->str, len);
		s->str[0] = nbr;
	}
}

void	rotate(t_stack *s)
{
	int	nbr;
	int	len;

	len = (s->size - 1) * sizeof(int);
	if (s->size)
	{
		nbr = s->str[0]; 
		ft_memmove(s->str, s->str + 1, len);
		s->str[s->size - 1] = nbr;
	}
}

void	swap(t_stack *s)
{
	int	nbr;

	if (s->size > 1)
	{
		nbr = s->str[0];
		s->str[0] = s->str[1];
		s->str[1] = nbr;
	}
}

