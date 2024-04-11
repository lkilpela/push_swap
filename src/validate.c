/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 11:25:01 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_duplicate(t_push_swap *ps)
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

int	arg_has_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}
void	invalid_arg(t_push_swap *ps)
{
	int	i;
	int nbr;

	i = 0;
	while (i < ps->argc)
	{
		if (ps->argv[1][0] == '\0')
			error(ERR_EMPTY_ARG);
		nbr = ft_atoi(ps->argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error(ERR_INT_OVERFLOW);
		if (arg_has_alpha(ps->argv[i]))
			error(ERR_FORMAT);
		i++;
	}
}

void	validate_argument(t_push_swap *ps)
{
	if (ps->argc < 2)
		error(ERR_NOT_ENOUGH_ARG);
	is_duplicate(ps);
	invalid_arg(ps);
}