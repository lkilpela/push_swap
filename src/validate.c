/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 09:23:51 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_duplicate(int *number, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (number[i] == number[j])
				return (true) ;
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_not_int(char *str)
{
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (true);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (true);
		str++;
	}
	return (false);
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
