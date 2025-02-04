/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:26:16 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/03 12:26:16 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*solve_3(t_stack *head)
{
	t_stack	*ptr;
	t_stack *ptr2;

	ptr = head -> up2down;
	ptr2 = ptr -> up2down;
	if (checker(head) == 1)
		return (head);
	if (checker(ptr) == 1)
		return (rotate(head));
	if (checker(ptr2) == 1)
		return (reverse_rotate(head));
	if (ptr -> content > head -> content && ptr -> content > ptr2 -> content)
		return (swap(head));
	if (head -> content < ptr -> content)
	{
		head = swap(head);
		return (reverse_rotate(head));
	}
	else
	{
		head = swap(head);
		return (rotate(head));
	}
}

void	target_max(t_stack *node_a, t_stack *head_B)
{
	t_stack	*target;
	t_stack *node_b;

	node_b = head_B -> up2down;
	target = node_b;
	while (node_b != head_B)
	{
		target = node_a -> target;
		if (target -> content < node_b -> content)
			node_a -> target = node_b;
		node_b = node_b -> up2down;
	}
}

void	target_min(t_stack *head_A, t_stack *head_B)
{
	t_stack	*node_a;
	t_stack *node_b;
	t_stack *target;

	node_a = head_A -> up2down;
	node_b = head_B -> up2down;
	while (node_a != head_A)
	{
		while (node_b != head_B)
		{
			target = node_a -> target;
			if (node_a ->content > node_b ->content
				&& target ->content < node_b ->content)
					node_a -> target = node_b;
			node_b = node_b -> up2down;
		}
		if (!node_a -> target)
			target_max(node_a, head_B);
		node_a = node_a -> up2down;
	}
}