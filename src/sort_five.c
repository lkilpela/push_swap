/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:35:42 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 23:45:41 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

https://github.com/gemartin99/Push_swap/blob/master/src/size5.c
void	size4(t_stack *s)
{
    int a = s->array[0];
    int b = s->array[1];
    int c = s->array[2];
    int d = s->array[3];

	if (s->size == 4)
	{
		if (a < b && a < c && a < d && s->size == 4)
			pb(s);
		if (a > b && b < c && b < d && s->size == 4)
		{
			sa(s);
			pb(s);
		}
		if (a > c && b > c && c < d && s->size == 4)
		{
			ra(s);
			sa(s);
			pb(s);
		}
		if (a > c && b > d && c > d && s->size == 4)
		{
			rra(s);
			pb(s);
		}
	}
	if (s->size == 3)
		sort_three(s);
	pa(s);
}

int	size5_2(t_stack *s, int i)
{
    int a = s->array[0];
    int b = s->array[1];
    int c = s->array[2];
    int d = s->array[3];
    int e = s->array[4];

	if (a > c && b > c && c < d && c < e && i == 0)
	{
		ra(s);
		sa(s);
		pb(s);
		i++;
	}
	if (a > d && b > d && c > d && d < e && i == 0)
	{
		rra(s);
		rra(s);
		pb(s);
		i++;
	}
	if (a > e && b > e && c > e && d > e && i == 0)
	{
		rra(s);
		pb(s);
		i++;
	}
	return (i);
}

void	size5(t_stack *s)
{
	int	i;
    int a = s->array[0];
    int b = s->array[1];
    int c = s->array[2];
    int d = s->array[3];
    int e = s->array[4];

	i = 0;
	if (s->size == 5)
	{
		if (a < b && a < c && a < d && a < e && i == 0)
		{
			pb(s);
			i++;
		}
		if (a > b && b < c && b < d && b < e && i == 0)
		{
			sa(s);
			pb(s);
			i++;
		}
		i = size5_2(s, d, i);
	}
	size4(s);
	if (i == 1)
	{
		pa(s);
		if (a > b)
			sa(s);
	}
}
