/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 15:22:32 by lkilpela         ###   ########.fr       */
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
	if (*str == '-' || *str == '+')
        str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
void	validate_argument(t_push_swap *ps)
{
	int		i;
	t_atoi	check;

	i = 1;
	while (i < ps->argc)
	{
		if (ps->argc < 2)
			error(ERR_NOT_ENOUGH_ARG);
		if (ps->argv[1][0] == '\0')
			error(ERR_EMPTY_ARG);
		is_duplicate(ps);
		if (arg_has_alpha(ps->argv[i]))
			error(ERR_FORMAT);
		check = check_atoi_overflow(ps->argv[i]);
		if (!check.valid)
			error(ERR_INT_OVERFLOW);
		i++;
	}
}
