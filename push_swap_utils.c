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

void	printer(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	ft_printf("%d\n", ptr ->content);
	ptr = ptr -> up2down;
	while (ptr != head)
	{
		ft_printf("%d\n", ptr ->content);
		ptr = ptr -> up2down;
	}
}

t_stack	*next_up(int content, t_stack *down2up)
{
	t_stack	*new;

	new = malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> down2up = down2up;
	return (new);
}

int	index(t_stack *head, t_stack *node)
{
	int	i;
	t_stack	*ptr;

	i = 0;
	if (head == node)
		return (i);
	ptr = head -> up2down;
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
