/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:05:49 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 22:15:11 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	if (s->str)
		free(s->str);
}

void	grow(t_stack *s)
{
	int	*str;

	str = malloc(sizeof(int) * s->capacity);
	if (!str)
		exit(1);
	ft_memcpy(str, s->str, sizeof(int) * s->capacity);
	free(s->str);
	s->str = str;
	s->capacity *= 2;
}
