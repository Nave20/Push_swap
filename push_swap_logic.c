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