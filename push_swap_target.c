/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:55:47 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/10 14:55:47 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_minimum(t_stack *node_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_b;

	node_b = head_b -> up2down;
	target = node_b;
	node_a -> target = head_b;
	while (node_b != head_b)
	{
		target = node_a -> target;
		if (target -> content > node_b -> content)
			node_a -> target = node_b;
		node_b = node_b -> up2down;
	}
}

void	target_upper(t_stack *node_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_b;

	node_b = head_b -> up2down;
	target = node_b;
	node_a -> target = head_b;
	while (node_b != head_b)
	{
		target = node_a -> target;
		if (target -> content > node_b -> content
			&& node_b -> content > node_a -> content)
			node_a -> target = node_b;
		else if (target -> content < node_a -> content)
			node_a -> target = node_b;
		node_b = node_b -> up2down;
	}
}

void	target_second(t_stack *head_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_a;

	node_a = head_a -> up2down;
	target_upper(node_a, head_b);
	target = node_a -> target;
	if (target -> content < node_a -> content)
		target_minimum(node_a, head_b);
	while (node_a != head_a)
	{
		node_a = node_a -> up2down;
		target_upper(node_a, head_b);
		target = node_a -> target;
		if (target -> content < node_a -> content)
			target_minimum(node_a, head_b);
	}
}