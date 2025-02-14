/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:14:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/14 11:14:53 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_5(t_stack *head_a)
{
	t_stack	*head_b;

	pb(&head_a, &head_b);
	pb(&head_a, &head_b);
	solve_3(head_a);
}

void	size_checker(t_stack *head_a)
{
	if (stack_count(head_a) == 3)
	{
		solve_3(head_a);
		stack_killer(head_a);
		return;
	}
	if (stack_count(head_a) == 5)
	{
		solve_5(head_a);
	}
}