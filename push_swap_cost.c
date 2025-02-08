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
		node_a -> to_head;
		node_a = node_a -> up2down;
	}
}

void	cost(t_stack *head_a, t_stack *head_b)
{
	t_stack	*node_a;
	t_stack	*target;

	to_head(head_a);
	to_head(head_b);
	node_a = head_a -> up2down;
	while (node_a != head_a)
	{

		node_a = node_a -> up2down;
	}
}