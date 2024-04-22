/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:05:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 12:13:00 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->capacity = 500;
	s->array = malloc(sizeof(int) * s->capacity);
	if (!s->array)
		exit(1);
	s->size = 0;
}

void	free_ptrs(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_stack(t_stack *s)
{
	if (s->array)
		free(s->array);
}

void	increase_capacity(t_stack *s)
{
	int	*str;

	str = malloc(sizeof(int) * (s->capacity * 2));
	if (!str)
		exit(1);
	ft_memcpy(str, s->array, sizeof(int) * s->capacity);
	free(s->array);
	s->array = str;
	s->capacity *= 2;
}
