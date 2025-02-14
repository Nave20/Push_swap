/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:52:01 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/10 09:52:01 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	n_move_b(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{
	t_stack	*target;

	target = node_a -> target;
	while (target -> n_moves < 0 && node_a -> n_moves < 0)
	{
		rrr(head_a, head_b);
		target -> n_moves++;
		node_a -> n_moves++;
	}
	while (target -> n_moves < 0)
	{
		rra(head_b);
		target -> n_moves++;
	}
	while (node_a -> n_moves < 0)
	{
		rrb(head_a);
		node_a -> n_moves++;
	}
}

void	p_move_b(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{
	t_stack	*target;

	target = node_a -> target;
	while (target -> p_moves > 0 && node_a -> p_moves > 0)
	{
		rr(head_a, head_b);
		target -> p_moves--;
		node_a -> p_moves--;
	}
	while (target -> p_moves > 0)
	{
		ra(head_b);
		target -> p_moves--;
	}
	while (node_a -> p_moves > 0)
	{
		rb(head_a);
		node_a -> p_moves--;
	}
}

void	mover_b(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{
	int		direction;

	direction = up_or_down(node_a);
	if (direction < 0)
	{
		n_move_b(node_a, head_a, head_b);
		pa(head_a, head_b);
	}
	else if (direction > 0)
	{
		p_move_b(node_a, head_a, head_b);
		pa(head_a, head_b);
	}
	else
	{
		n_move_b(node_a, head_a, head_b);
		p_move_b(node_a, head_a, head_b);
		pa(head_a, head_b);
	}
}

int	rev_checker(t_stack *head)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = head -> down2up;
	ptr2 = head;
	while (ptr != head)
	{
		if (ptr2 -> content > ptr -> content)
			return (0);
		ptr2 = ptr;
		ptr = ptr -> down2up;
	}
	return (1);
}

void	order_last(t_stack **head_a)
{
	t_stack	*ptr;
	t_stack	*lst;

	ptr = (*head_a) -> up2down;
	lst = (*head_a)	-> down2up;
	if ((*head_a) -> content > ptr -> content
		&& (*head_a) -> content > lst -> content)
		rb(head_a);
	else if ((*head_a) -> content < ptr -> content
	&& (*head_a) -> content < lst -> content)
		rb(head_a);
}
