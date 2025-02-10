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

#include <stdio.h>

#include "push_swap.h"

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
	int		direction;

	direction = up_or_down(node_a);
	if (direction < 0)
	{
		n_move(node_a, head_a, head_b);
		pb(head_a, head_b);
	}
	else if (direction > 0)
	{
		p_move(node_a, head_a, head_b);
		pb(head_a, head_b);
	}
	else
	{
		n_move(node_a, head_a, head_b);
		p_move(node_a, head_a, head_b);
		pb(head_a, head_b);
	}
}

void	solver(t_stack **head_a, t_stack **head_b)
{
	t_stack	*node;
	int		count;

	count = stack_count(*head_a);
	pb(head_a, head_b);
	pb(head_a, head_b);
	while (stack_count(*head_a) > 3)
	{
		target(*head_a, *head_b);
		cost(*head_a, *head_b);
		node = to_move(*head_a);
		// ft_printf("to move -> %d\n", node -> content);
		// ft_printf("n_moves -> %d\n", node -> n_moves);
		// ft_printf("p_moves -> %d\n", node -> p_moves);
		// 	printer(*head_a);
		// 	ft_printf("\n");
		// 	target(*head_b, *head_a);
		// 	cost(*head_b, *head_a);
		// 	printer(*head_b);
		mover(node, head_a, head_b);
	}
	*head_a = solve_3(*head_a);
	target(*head_b, *head_a);
	cost(*head_b, *head_a);
	// while (stack_count(*head_a) < count)
	// {
	// 	target(*head_b, *head_a);
	// 	cost(*head_b, *head_a);
	// 	node = to_move(*head_b);
	// 	mover_b(node, head_b, head_a);
	// }
}
