/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:57:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/17 20:56:01 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	init_push_swap(argc, argv, &ps);
	validate_argument(&ps);
	init_node_a(&ps);
	if (!stack_sorted(ps.a))
	{
		if (stack_size(ps.a) == 2)
			sa(&ps.a, false);
		else if (stack_size(ps.a) == 3)
			sort_three(&ps.a);
		else
			sort_stacks(&ps.a, &ps.b);
	}
	return (0);
}
