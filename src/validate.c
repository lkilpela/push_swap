/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 13:53:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_duplicate(t_push_swap *ps)
{
	int	flg;
	int	i;
	int	j;

	flg = 0;
	i = 1;
	while (i < ps->argc)
	{
		j = i + 1;
		while (j < ps->argc && !flg)
		{
			if(ft_atoi(ps->argv[i]) == ft_atoi(ps->argv[j]))
				flg = 1;
			j++;
		}
		i++;
	}
	if (flg)
		error(ERR_DUPLICATE);
}

static int	arg_has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}
static void	invalid_arg(t_push_swap *ps)
{
	int	i;
	int nbr;

	i = 1;
	while (i < ps->argc)
	{
		nbr = ft_atoi(ps->argv[i]);
		printf("ps->argc: %d\n", ps->argc);
		for (int j = 0; j < ps->argc; j++)
			printf("ps->argv[i]: %s\n", ps->argv[j]);
		if (ps->argv[1][0] == '\0')
			error(ERR_EMPTY_ARG);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(ERR_INT_OVERFLOW);
		if (arg_has_alpha(ps->argv[i]))
			error(ERR_FORMAT);
		i++;
	}
}

void	validate_argument(t_push_swap *ps)
{
	if (ps->argc > 2)
	{
		invalid_arg(ps);
		is_duplicate(ps);
	}
	else
		error(ERR_NOT_ENOUGH_ARG);
}