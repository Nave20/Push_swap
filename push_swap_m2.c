/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_m2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:48:38 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/08 14:48:38 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **head_a, t_stack **head_b)
{
	ft_printf("rrr\n");
	*head_a = reverse_rotate(*head_a);
	*head_b = reverse_rotate(*head_b);
}

void	sa(t_stack **head_a)
{
	ft_printf("sa\n");
	*head_a = swap(*head_a);
}

void	sb(t_stack **head_b)
{
	ft_printf("sb\n");
	*head_b = swap(*head_b);
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	ft_printf("ss\n");
	*head_a = swap(*head_a);
	*head_b = swap(*head_b);
}

void	pa(t_stack **head_a, t_stack **head_b)
{
	ft_printf("pa\n");
	*head_b = push(head_a, *head_b);
}