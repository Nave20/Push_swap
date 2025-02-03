/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 07:55:01 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/03 07:55:01 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_rotate(t_stack *head)
{
	head = head -> down2up;
	return (head);
}

t_stack	*rotate(t_stack *head)
{
	head = head -> up2down;
	return (head);
}

t_stack *swap(t_stack *head)
{
	t_stack *ptr;
	t_stack *ptr2;
	t_stack *ptr3;

	ptr = head -> down2up;
	ptr2 = head -> up2down;
	ptr3 = ptr2 -> up2down;
	ptr -> up2down = ptr2;
	ptr2 -> down2up = ptr;
	ptr2 -> up2down = head;
	head -> down2up = ptr2;
	head -> up2down = ptr3;
	ptr3 -> down2up = head;
	return (ptr2);
}

t_stack	*push(t_stack **head_a, t_stack *head_b)
{
	t_stack	*ptr;
	t_stack *ptr2;

	ptr = stack_extract(*head_a);
	if (!head_b)
	{
		head_b = *head_a;
		*head_a = ptr;
		return (head_b);
	}
	else
	{
		head_b -> down2up = *head_a;
		ptr2 = *head_a;
		ptr2 -> up2down = head_b;
		head_b = *head_a;
		*head_a = ptr;
		return (head_b);
	}
}