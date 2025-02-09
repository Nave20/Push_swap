/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:17:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/03 15:17:51 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_no_rep(t_stack *head)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = head -> up2down;
	ptr2 = ptr -> up2down;
	while (ptr != head)
	{
		while (ptr2 != ptr)
		{
			if (ptr -> content == ptr2 -> content)
				return (0);
			ptr2 = ptr2 -> up2down;
		}
		ptr = ptr -> up2down;
	}
	return (1);
}
