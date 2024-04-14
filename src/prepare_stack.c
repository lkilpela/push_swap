/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 12:22:30 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/14 12:28:13 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node    *get_cheapest(t_stack_node *n)
{
    if (!n)
        return (NULL);
    while (n)
    {
        if (n->cheapest)
            return (n);
        n = n->next;        
    }
    return (NULL);
}
