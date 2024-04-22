/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:56:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 10:39:36 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
case1 : [2,1,3]->sa->[1,2,3].
case2 : [3,2,1]->sa->[2,3,1]->rra->[1,2,3].
case3 : [3,1,2]->ra->[1,2,3].
case4 : [1,3,2]->sa->[3,1,2]->ra->[1,2,3].
case5 : [2,3,1]->rra->[1,2,3].
*/
static void	print_rotate(t_stack *s)
{
	rotate(s);
	ft_printf("ra\n");
}

void	sort_three(t_stack* s)
{
	int a = s->array[0];
	int b = s->array[1];
	int c = s->array[2];

	if (a > b && a < c)
		swap(s);
	else if (a > b && b > c)
	{
		swap(s);
		reverse_rotate(s);
		ft_printf("rra\n");
	}
	else if (a > b && b < c)   
		print_rotate(s);
	else if (a < b && b > c && a < c)
	{
		swap(s);
		print_rotate(s);
	}
	else if (a < b && a > c)
	{
		reverse_rotate(s);
		ft_printf("rra\n");
	}
}
