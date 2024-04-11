/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:43 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 14:33:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_overflow(long long result, int sign, int digit)
{
	if ((sign == 1 && result > (INT_MAX - digit) / 10)
		|| (sign == -1 && result < (INT_MIN + digit) / 10))
		return (1);
	return (0);
}

t_atoi	check_atoi_overflow(const char *str)
{
    int			sign;
	int			digit;
    long long	result;
	t_atoi		i;
    
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
		if (ft_is_overflow(result, sign, digit))
		{
			i.valid = 0;
			return (i);
		}
		result = (result * 10) + (digit * sign);
		str++;
	}
	i.valid = 1;
	i.number = (int)result;
	return (result);
}