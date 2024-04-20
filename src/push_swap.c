/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:57:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:36:16 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepare_argv(int argc, char **argv)
{
	char	**argv_split;

	argv_split = NULL;
	error_if(argc == 1 || (argc == 2 && !argv[1][0]));
	if (argc == 2)
	{
		argv_split = ft_split(argv[1], ' ');
		return (argv_split);
	}
	else
		return NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char			**argv_split;

	a = NULL;
	b = NULL;
	argv_split = prepare_argv(argc, argv);
	if (argv_split)
		argv = argv_split;
	else
		argv = argv + 1;
	init_stack_a(&a, argv);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, false);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (argv_split && argc == 2)
		free_ptrs(argv_split);
	stack_clear(&a);
	return (0);
}
