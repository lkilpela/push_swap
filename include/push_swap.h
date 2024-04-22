/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:58:45 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/22 11:06:32 by lkilpela         ###   ########.fr       */
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

//Operations
void	swap(t_stack *s);
void	reverse_rotate(t_stack *s);
void	rotate(t_stack *s);
void	do_optimal_push(t_stack *a, t_stack *b);
void	rotate_stack(char *name, t_stack *a, int index, int moves);
//Stack prep
void	build_stack(t_stack *s, char **argv);
void	push_to_top(t_stack *s, int new_value);
void	push_to_back(t_stack *s, int new_value);
int		remove_top(t_stack *s);
int		find_insert_location(t_stack *s, int new_value);
void	rotate_to_sort_stack(char *name, t_stack *s);
int		find_smallest(int *array, int size);
int		find_biggest(t_stack *s);
int		calculate_min_rotations(t_stack *s, int i);
//Algorithms
int		is_sorted(t_stack *s);
void	sort(t_stack *s);
void	sort_three(t_stack *s);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
//Utils
void	init_stack(t_stack *s);
void	free_stack(t_stack *s);
void	increase_capacity(t_stack *s);
void	free_ptrs(char **array);
// Handle errors
void	error_if(int status);
#endif