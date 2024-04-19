/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:02:10 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/19 09:25:17 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



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
