/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:58:26 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 17:16:16 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;

    init_stack(&a);
    build_stack(&a, argv + 1);
    print_sort_stack(&a);
    free_stack(&a);
}