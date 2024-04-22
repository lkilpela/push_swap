/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:58:26 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 10:48:06 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**prepare_argv(int argc, char **argv)
{
	char	**argv_split;

	argv_split = NULL;
	if (argc == 2 && !argv[1][0])
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (argc == 2)
	{
		argv_split = ft_split(argv[1], ' ');
		return (argv_split);
	}
	else
		return (NULL);
}

int main(int argc, char **argv)
{
	t_stack		a;
	char		**argv_split;

	init_stack(&a);
	if (argc == 1)
		return (0);
	argv_split = prepare_argv(argc, argv);
	if (argv_split)
		build_stack(&a, argv_split);
	else
		build_stack(&a, argv + 1);
	sort(&a);
	if (argv_split && argc == 2)
		free_ptrs(argv_split);
	free_stack(&a);
	return (0);
}
