/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 10:09:19 by lkilpela         ###   ########.fr       */
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

void	invalid_arg(t_push_swap *ps)
{
	
}

void	validate_argument(t_push_swap *ps)
{
	if (ps->argc < 2)
		error(ERR_NOT_ENOUGH_ARG);
	is_duplicate(ps);
		
}