/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:06:53 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/07 16:06:53 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

#include "push_swap.h"

void	to_head(t_stack *head_a)
{
	t_stack	*node_a;
	int		stack;
	int		index;

	node_a = head_a -> up2down;
	stack = stack_count(head_a);
	moves_reset(head_a);
	while (node_a != head_a)
	{
		index = stack_index(head_a, node_a);
		if (index < stack / 2)
			node_a -> to_head = index;
		else
			node_a -> to_head = (stack - (index)) * -1;
		if (node_a -> to_head < 0)
			node_a -> n_moves = node_a -> to_head;
		else
			node_a -> p_moves = node_a -> to_head;
		node_a = node_a -> up2down;
	}
}

int	smallest(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	cost_logic(t_stack *node_a)
{
	t_stack	*target;

	target = node_a -> target;
	if ((node_a -> p_moves > 0 && target -> n_moves < 0)
		|| (node_a -> n_moves < 0 && target -> p_moves > 0))
	{
		node_a -> cost = node_a -> p_moves + (node_a ->n_moves) * -1
			+ (target -> n_moves) * -1 + target -> p_moves;
	}
	else if (node_a -> p_moves > 0 || target -> p_moves > 0)
		node_a -> cost = greatest(node_a ->p_moves, target->p_moves);
	else
		node_a -> cost = smallest(node_a ->n_moves, target->n_moves) * -1;
}

void	cost(t_stack *head_a, t_stack *head_b)
{
	t_stack	*node_a;

	to_head(head_a);
	to_head(head_b);
	cost_logic(head_a);
	node_a = head_a -> up2down;
	while (node_a != head_a)
	{
		cost_logic(node_a);
		node_a = node_a -> up2down;
	}
}

t_stack	*to_move(t_stack *head_a)
{
	t_stack	*node_a;
	t_stack	*to_move;

	to_move = head_a;
	node_a = head_a -> up2down;
	while (node_a != head_a)
	{
		if (node_a -> cost < to_move -> cost)
			to_move = node_a;
		node_a = node_a -> up2down;
	}
	return (to_move);
}
