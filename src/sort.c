/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:28:23 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 23:33:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *s)
{
    int i;

    i = 0;
    if (s->size < 2)
        return (1);
    while (i < s->size - 1)
    {
        if (s->str[i] > s->str[i + 1])
            return (0);
        i++;
    }
    return (1);    
}
void    sort(t_stack *s)
{
    t_stack b;

    if (!is_sorted(s))
    {
        init_stack(&b);
        while (s->size > 0)
    }
}