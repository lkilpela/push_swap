/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/13 14:57:53 by lkilpela         ###   ########.fr       */
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
static int	is_not_int(const char *str)
{
	while (ft_isspace(*str))
        str++;
	if (*str == '-' || *str == '+')
        str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1); // return 1 when a non-digit character is found
		str++;
	}
	return (0);// return 0 if all characters are digits (or the string is empty)
}

static void	validate_single_argument(t_push_swap *ps)
{
	t_atoi	check;

	ft_printf("ps->arg: %s\n", ps->arg);
	if (ps->arg[0] == '\0')
		error(ERR_EMPTY_ARG);
	if (is_not_int(ps->arg))
		error(ERR_FORMAT);
	check = check_atoi_overflow(ps->arg);
	if (check.valid == 1)
		error(ERR_INT_OVERFLOW);
	is_duplicate(ps);
}

int	validate_argument(t_push_swap *ps)
{
	int		i;
	int		j;

	if (ps->argc >= 2)
	{
		i = 1;
		while (i < ps->argc)
		{
			ft_printf("ps->argv[1]: %s\n", ps->argv[1]);
			ps->tab = ft_split(ps->argv[1], ' ');
			if (!ps->tab)
				return (0);
			j = 0;
			while (ps->tab[j])
			{
				ft_printf("tab[j]: %s\n", ps->tab[j]);
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
