/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/20 22:09:23 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"

# include <stdbool.h>
# include <limits.h> // INT_MIN, INT_MAX
# include <unistd.h> // read, write
# include <stdlib.h> // malloc, free, exit
# include <stdio.h>

typedef struct s_stack
{
	int	*str;
	int	size;
	int capacity;
}				t_stack;

//Handle errors
//int				validate_argument(int argc, char **argv);
void			error_if(bool status);
// argument initiation
//Stack preparation

//Nodes initiation

//Commands

//Algorithms

//Utils

//Handle memory

#endif