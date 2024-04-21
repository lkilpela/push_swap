/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:58:26 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 17:17:04 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;

    init_stack(&a);
    build_stack(&a, argv + 1);
    sort(&a);
    free_stack(&a);
}