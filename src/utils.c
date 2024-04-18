/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/18 21:17:43 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(long long result, int sign, int digit)
{
	if ((sign == 1 && result > INT_MAX / 10 - digit)
		|| (sign == -1 && result < INT_MIN / 10 + digit))
		return (1);
	return (0);
}

t_atol	check_atol_overflow(const char *str)
{
	int			sign;
	int			digit;
	long long	result;
	t_atol		check;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (is_overflow(result, sign, digit))
		{
			check.valid = 1;
			return (check);
		}
		result = (result * 10) + (digit * sign);
		str++;
	}
	check.valid = 0;
	check.number = (int)result;
	return (check);
}

// Search a stack and returns the node with the biggest number
t_stack_node	*find_max(t_stack_node *head)
{
	long			max;
	t_stack_node	*max_node;

	if (!head)
		return (NULL);
	max = LONG_MIN;
	max_node = NULL;
	while (head)
	{
		if (head->nbr > max)
		{
			max = head->nbr;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

// Search a stack and returns the node with the smallest number
t_stack_node	*find_min(t_stack_node *head)
{
	long			min;
	t_stack_node	*min_node;

	if (!head)
		return (NULL);
	min = LONG_MAX;
	while (head)
	{
		if (head->nbr < min)
		{
			min = head->nbr;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

int	stack_size(t_stack_node *head)
{
	int	i;

	i = 0;
	if (!head)
		return (0);
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

t_stack_node	*stack_last(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
