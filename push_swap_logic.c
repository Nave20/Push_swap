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
	t_stack	*ptr2;

	ptr = head -> up2down;
	ptr2 = ptr -> up2down;
	if (checker(head) == 1)
		return (head);
	else if (checker(ptr) == 1)
		ra(&head);
	else if (checker(ptr2) == 1)
		rra(&head);
	else if (ptr -> content < head -> content && ptr -> content < ptr2 -> content)
		sa(&head);
	else if (head -> content > ptr -> content)
	{
		sa(&head);
		rra(&head);
	}
	else
	{
		sa(&head);
		ra(&head);
	}
	return (head);
}

void	target_max(t_stack *node_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_b;

	node_b = head_b -> up2down;
	target = node_b;
	node_a -> target = head_b;
	while (node_b != head_b)
	{
		target = node_a -> target;
		if (target -> content < node_b -> content)
			node_a -> target = node_b;
		node_b = node_b -> up2down;
	}
}

void	target_min(t_stack *node_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_b;

	node_b = head_b -> up2down;
	target = node_b;
	node_a -> target = head_b;
	while (node_b != head_b)
	{
		target = node_a -> target;
		if (target -> content < node_b -> content
			&& node_b -> content < node_a -> content)
			node_a -> target = node_b;
		else if (target -> content > node_a -> content)
			node_a -> target = node_b;
		node_b = node_b -> up2down;
	}
}

void	target(t_stack *head_a, t_stack *head_b)
{
	t_stack	*target;
	t_stack	*node_a;

	node_a = head_a -> up2down;
	target_min(node_a, head_b);
	target = node_a -> target;
	if (target -> content > node_a -> content)
		target_max(node_a, head_b);
	while (node_a != head_a)
	{
		node_a = node_a -> up2down;
		target_min(node_a, head_b);
		target = node_a -> target;
		if (target -> content > node_a -> content)
			target_max(node_a, head_b);
	}
}
