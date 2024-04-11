/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkilpela <lkilpela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:57:54 by lkilpela          #+#    #+#             */
/*   Updated: 2024/04/11 13:41:18 by lkilpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	//t_stack_node	*a;
	//t_stack_node	*b;
	t_push_swap		ps;

	//a = NULL;
	//b = NULL;
	init_push_swap(argc, argv, &ps);
	validate_argument(&ps);
	return (0);
}
