/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:01:14 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/16 22:49:38 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*get_error_messages(int e)
{
	static const char   *error_messages[] = {
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
}

void	error(int e)
{
	const char	*message;

	if (e >= 0 || e < LAST_ERROR)
	{
		message = get_error_messages(e);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
	}
	else
		ft_putstr_fd ("Unknown error", STDERR_FILENO);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
