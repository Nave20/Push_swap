/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_m1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:41:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/08 14:41:51 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **head_a)
{
	ft_printf("ra\n");
	*head_a = rotate(*head_a);
}

void	rb(t_stack **head_b)
{
	ft_printf("rb\n");
	*head_b = rotate(*head_b);
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ft_printf("rr\n");
	*head_a = rotate(*head_a);
	*head_b = rotate(*head_b);
}

void	rra(t_stack **head_a)
{
	ft_printf("rra\n");
	*head_a = reverse_rotate(*head_a);
}

void	rrb(t_stack **head_b)
{
	ft_printf("rrb\n");
	*head_b = reverse_rotate(*head_b);
}
