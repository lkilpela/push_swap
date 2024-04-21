/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:56:46 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 23:27:25 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack* s)
{
    int a = s->array[0];
    int b = s->array[1];
    int c = s->array[2];

    if ((a < b && b < c) || (b < c && c < a))
    {
        if (b < c && c < a)
			swap(s);
    }
    else if (c < a && a < b)
	{
        rotate(s);
		ft_printf("ra\n");
	}
    else if (a < c && c < b)
	{
        reverse_rotate(s);
		ft_printf("rra\n");
	}
    else if (b < a && a < c)
    {
        swap(s);
		ft_printf("swap\n");
        rotate(s);
		ft_printf("rotate\n");
	}
	else if (b < c && c < a)
	{
		swap(s);
		ft_printf("swap\n");
		reverse_rotate(s);
		ft_printf("rrotate\n");
    }
    else if (c < b && b < a)
    {
		swap(s);
		ft_printf("swap\n");
		reverse_rotate(s);
		ft_printf("rrotate\n");
    }
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