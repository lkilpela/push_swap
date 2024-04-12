/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/12 07:04:51 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_overflow(long long result, int sign, int digit)
{
	if ((sign == 1 && result > INT_MAX / 10 - digit)
		|| (sign == -1 && result < INT_MIN / 10 + digit))
		return (1);
	return (0);
}

t_atoi	check_atoi_overflow(const char *str)
{
    int			sign;
	int			digit;
    long long	result;
	t_atoi		check;
    
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
