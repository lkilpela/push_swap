/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:08:24 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 20:00:45 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overflow(long result, long sign, long digit)
{
	if ((sign == 1 && result > (LONG_MAX - digit) / 10)
		|| (sign == -1 && result < (LONG_MIN + digit) / 10))
		return (1);
	return (0);
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;
	long	digit;

	result = 0;
	sign = 1;
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
			return (0);
		}
		result = (result * 10) + (digit * sign);
		str++;
	}
	return (result);
}
