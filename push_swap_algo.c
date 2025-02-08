/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:02:57 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/07 16:02:57 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node_a;

	*head_b = push(head_a, *head_b);
	*head_b = push(head_a, *head_b);
	while (stack_count(*head_a) > 3)
	{
		target(*head_a, *head_b);
		cost(*head_a, *head_b);
		node_a = to_move(*head_a);
	}
	*head_a = solve_3(*head_a);

}

void	mover(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{

}