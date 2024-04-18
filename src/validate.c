/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/18 21:46:31 by lkilpela         ###   ########.fr       */
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
			if (ft_atol(ps->argv[i]) == ft_atol(ps->argv[j]))
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
static int	is_not_int(const char *str)
{
	int		has_digit;

	has_digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		has_digit = 1;
		str++;
	}
	return (!has_digit);
}

static void	validate_single_argument(t_push_swap *ps)
{
	t_atol	check;

	if (is_not_int(ps->arg))
		error(ERR_FORMAT);
	check = check_atol_overflow(ps->arg);
	if (check.valid == 1)
		error(ERR_INT_OVERFLOW);
	is_duplicate(ps);
}

int	validate_argument(t_push_swap *ps)
{
	int		i;
	int		j;
	long	n;

	if (ps->argc >= 2)
	{
		i = 1;
		while (i < ps->argc)
		{
			if (ps->argv[i][0] == '\0')
				error(ERR_EMPTY_ARG);
			n = ft_atol(ps->argv[i]);
			if (n > INT_MAX || n < INT_MIN)
				error(ERR_INT_OVERFLOW);
			//if (is_not_int(ps->argv[i]))
				//error(ERR_FORMAT);
			ps->tab = ft_split(ps->argv[i], ' ');
			if (!ps->tab)
				return (0);
			j = 0;
			while (ps->tab[j])
			{
				ps->arg = ps->tab[j];
				validate_single_argument(ps);
				j++;
			}
			free_ptrs(ps->tab);
			i++;
		}
	}
	else
		error(ERR_NOT_ENOUGH_ARG);
	return (0);
}
