/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 15:44:29 by lkilpela         ###   ########.fr       */
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
/* returns 1, the string contains an alphabetic character. 
returns 0, the string does not contain any alphabetic characters.*/
static int	check_alpha(char *str)
{
	if (*str == '-' || *str == '+')
        str++;
	while (*str)
	{
		if (ft_isalpha(*str))
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
	if (ps->argc > 2)
	{
		while (i < ps->argc)
		{
			check = check_atoi_overflow(ps->argv[i]);
			if (ps->argv[1][0] == '\0')
				error(ERR_EMPTY_ARG);
			is_duplicate(ps);
			if (!check_alpha(ps->argv[i]))
				error(ERR_FORMAT);
			if (check.valid)
				error(ERR_INT_OVERFLOW);
			i++;
		}
	}
	else
		error(ERR_NOT_ENOUGH_ARG);
}
