/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:01:14 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/18 21:30:47 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int e)
{
	if (e >= 0 || e < LAST_ERROR)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
	}
	else
		ft_putstr_fd ("Unknown error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/*static const char	*get_error_messages(int e)
{
	static const char	*error_messages[] = {
		"No error",
		"Not enough arguments.",
		"Invalid argument: integer overflow.",
		"Invalid argument: format.",
		"Empty argument.",
		"Duplicate values.",
		"Memory allocation failed",
		"Last error"
	};

	return (error_messages[e]);
}*/