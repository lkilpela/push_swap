/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 09:03:43 by lkilpela         ###   ########.fr       */
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

static void	validate_single_argument(char *str)
{
	t_atol	check;

	error(is_not_int(str));
	check = check_atol_overflow(str);
	error(check.valid == 1);
	
}

void	validate_argument(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;

	if (argc = 2)
	{
		i = 1;
		while (i < argc)
		{
			tab = ft_split(argv[i], ' ');
			if (!tab)
				return (0);
			j = 0;
			while (tab[j])
			{
				validate_single_argument(tab[j]);
				j++;
			}
			free_ptrs(tab);
			i++;
		}
	}
}
