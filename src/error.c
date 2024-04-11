/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 09:01:14 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 09:19:52 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char   *get_error_messages(int e)
{
    static const char   *error_messages[] = {
        "No error",
        "Error\nNot enough arguments.",
        "Error\nInvalid argument format or integer overflow.",
        "Error\nEmpty argument.",
        "Error\nDuplicate values.",
    }
}

	ERR_NOT_ENOUGH_ARG,
	
	ERR_INVALID_ARG,
	ERR_EMPTY_ARG,
	ERR_DUPLICATE