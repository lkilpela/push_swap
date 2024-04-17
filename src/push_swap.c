/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:57:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/17 10:07:42 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_push_swap		ps;

	init_push_swap(argc, argv, &ps);
	validate_argument(&ps);
	init_node_a(&ps);
	if (!stack_sorted(ps.a));
	{
		if (stack_size(ps.a) == 2)
			sa(&ps.a, false);
	}
	return (0);
}
