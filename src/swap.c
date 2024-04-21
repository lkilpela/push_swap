/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:13:29 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 23:10:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	nbr;

	if (s->size > 1)
	{
		nbr = s->array[0];
		s->array[0] = s->array[1];
		s->array[1] = nbr;
	}
	ft_printf("sa\n");
}
