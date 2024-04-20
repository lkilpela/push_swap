/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:41:41 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 17:36:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Free an array of pointers
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
static void	stack_delone(t_stack *head)
{
	if (!head)
		return ;
	head->nbr = 0;
	free(head);
}

void	stack_clear(t_stack **head)
{
	t_stack	*temp;

	if (!*head)
		return ;
	while (*head)
	{
		temp = (*head)->next;
		stack_delone(*head);
		*head = temp;
	}
	*head = NULL;
}
