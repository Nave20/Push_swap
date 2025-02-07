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

#include "push_swap.h"

void	cost(t_stack *head_a, t_stack *head_b)
{
	t_stack	*node_a;
	t_stack *target;
	t_stack	*node_b;

	node_a = head_a -> up2down;
	while (node_a != head_a)
	{

		node_a = node_a -> up2down;
	}
}