/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 08:23:55 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/03 08:23:55 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	printer(t_stack *head)
// {
// 	t_stack	*ptr;
// 	t_stack	*target;
//
// 	ptr = head;
// 	target = ptr -> target;
// 	ft_printf("%d", ptr ->content);
// 	ft_printf(" -> %d", target -> content);
// 	ft_printf(" | cost : %d", ptr -> cost);
// 	ft_printf(" | to head : %d\n", ptr -> to_head);
// 	ptr = ptr -> up2down;
// 	while (ptr != head)
// 	{
// 		target = ptr -> target;
// 		ft_printf("%d", ptr ->content);
// 		ft_printf(" -> %d", target -> content);
// 		ft_printf(" | cost : %d", ptr -> cost);
// 		ft_printf(" | to head : %d\n", ptr -> to_head);
// 		ptr = ptr -> up2down;
// 	}
// }

t_stack	*next_up(int content, t_stack *down2up)
{
	t_stack	*new;

	new = malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> down2up = down2up;
	new -> cost = 0;
	new -> to_head = 0;
	new -> p_moves = 0;
	new -> n_moves = 0;
	new -> target = NULL;
	return (new);
}

int	stack_index(t_stack *head, t_stack *node)
{
	int		i;
	t_stack	*ptr;

	i = 0;
	if (head == node)
		return (i);
	ptr = head -> up2down;
	i++;
	while (ptr != node)
	{
		ptr = ptr -> up2down;
		i++;
	}
	return (i);
}

int	checker(t_stack *head)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = head -> up2down;
	ptr2 = head;
	while (ptr != head)
	{
		if (ptr2 -> content > ptr -> content)
			return (0);
		ptr2 = ptr;
		ptr = ptr -> up2down;
	}
	return (1);
}

int	greatest(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

void	moves_reset(t_stack *head_a)
{
	t_stack	*node;

	head_a -> n_moves = 0;
	head_a -> p_moves = 0;
	node = head_a -> up2down;
	while (node != head_a)
	{
		node -> n_moves = 0;
		node -> p_moves = 0;
		node = node -> up2down;
	}
}
