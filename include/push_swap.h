/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/21 16:28:41 by lkilpela         ###   ########.fr       */
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
	int	*array;		// Pointer to the array that holds elements of the stack
	int	size;		// Current number of elements in the stack
	int	capacity;	// Maximum number of elements the stack can hold
}				t_stack;

// Handle errors
void	error_if(bool status);

//Operations
void	swap(t_stack *s);
void	rotate_stack(char *name, t_stack *a, int index, int moves);
void	push_a_to_b(t_stack *a, int index, t_stack *b);

//Stack prep
void	push_to_top(t_stack *s, int nbr);
int		remove_top(t_stack *s);
int		min_rotation(t_stack *s, int index);
int		calculate_min_rotations(t_stack *s, int index);
void	rotate_to_sort_stack(char *name, t_stack *s);

//Algorithms
int		is_sorted(t_stack *s);
void	sort(t_stack *s);


//Utils
void	init_stack(t_stack *s);
void	free_stack(t_stack *s);
void	increase_capacity(t_stack *s);
//Handle memory

#endif