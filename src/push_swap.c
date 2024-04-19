/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:57:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 10:36:33 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	ft_printf("argv[1]: %s\n", argv[1]);
	ft_printf("argv[2]: %s\n", argv[2]);
	error_if(argc == 1 || (argc == 2 && !argv[1][0]));
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	init_stack_a(&a, argv);
	ft_printf("init argv[1]: %s\n", argv[2]);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	stack_clear(&a);
	return (0);
}
