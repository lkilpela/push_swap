/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:56:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 23:32:31 by lkilpela         ###   ########.fr       */
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

void	sort_three(t_stack* s)
{
    int a = s->array[0];
    int b = s->array[1];
    int c = s->array[2];

	if (a > b && a < c)        // case 1: [2,1,3]
        sa(s);
    else if (a > b && b > c)   // case 2: [3,2,1]
    {
        sa(s);
        rra(s);
    }
    else if (a > b && b < c)   // case 3: [3,1,2]
        ra(s);
    else if (a < b && b > c)   // case 4: [1,3,2]
    {
        sa(s);
        ra(s);
    }
    else if (a < b && a > c)   // case 5: [2,3,1]
        rra(s);
}


	/*if (s->array[0] > s->array[1])
		swap(s);
	if (s->array[1] > s->array[2])
	{
		reverse_rotate(s);
		ft_printf("rra\n");
	}
	if (s->array[0] > s->array[1])
		swap(s);
	if (s->array[0] == find_biggest(s))
	{
		reverse_rotate(s);
		ft_printf("rra\n");
	}*/