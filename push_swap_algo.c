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

int	up_or_down(t_stack *node_a)
{
	t_stack	*target;

	target = node_a -> target;
	if (target -> n_moves < 0 && node_a -> n_moves < 0)
		return (-1);
	if (target -> n_moves < 0 && node_a -> n_moves == 0)
		return (-1);
	if (target -> n_moves == 0 && node_a -> n_moves < 0)
		return (-1);
	if (target -> p_moves > 0 && node_a -> p_moves > 0)
		return (1);
	if (target -> p_moves > 0 && node_a -> p_moves == 0)
		return (1);
	if (target -> p_moves == 0 && node_a -> p_moves > 0)
		return (1);
	return (0);
}

void	n_move(t_stack *node_a, t_stack **head_a, t_stack **head_b)
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
		rrb(head_b);
		target -> n_moves++;
	}
	while (node_a -> n_moves < 0)
	{
		rra(head_a);
		node_a -> n_moves++;
	}
}

void	p_move(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{
	t_stack	*target;

	target = node_a -> target;
	while (target -> p_moves > 0 && node_a -> p_moves > 0)
	{
		rr(head_a, head_b);
		target -> p_moves--;
		node_a -> p_moves--;
	}
	while (target -> n_moves > 0)
	{
		rb(head_b);
		target -> p_moves--;
	}
	while (node_a -> p_moves > 0)
	{
		ra(head_a);
		node_a -> p_moves--;
	}
}

void	mover(t_stack *node_a, t_stack **head_a, t_stack **head_b)
{
	t_stack	*target;
	int		direction;

	target = node_a -> target;
	direction = up_or_down(node_a);
	if (direction < 0)
	{
		n_move(node_a, head_a, head_b);
		*head_b = push(head_a, *head_b);
	}
	else if (direction > 0)
	{
		p_move(node_a, head_a, head_b);
		*head_b = push(head_a, *head_b);
	}
	else
	{
		n_move(node_a, head_a, head_b);
		p_move(node_a, head_a, head_b);
		*head_b = push(head_a, *head_b);
	}
}
