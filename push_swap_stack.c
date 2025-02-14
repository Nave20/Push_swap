/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:42:17 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/02 09:42:17 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rounder(t_stack *head)
{
	t_stack	*ptr;

	ptr = head;
	ptr = ptr -> up2down;
	while (ptr -> up2down && ptr != head)
	{
		ptr = ptr -> up2down;
	}
	head -> down2up = ptr;
	ptr -> up2down = head;
}

t_stack	*new_stack(char **argv)
{
	t_stack	*new;
	t_stack	*temp;
	t_stack	*next;
	int		i;

	i = 1;
	new = next_up(ft_atoi(argv[i]), NULL);
	if (!new)
		return (NULL);
	next = new;
	while (argv[++i])
	{
		temp = next_up(ft_atoi(argv[i]), next);
		if (temp == NULL)
			return (stack_killer(new), NULL);
		next -> up2down = temp;
		next = temp;
	}
	next -> up2down = new;
	new -> down2up = next;
	return (new);
}

void	stack_killer(t_stack *head)
{
	t_stack	*ptr;

	ptr = head -> down2up;
	ptr -> up2down = NULL;
	ptr = head;
	while (head -> up2down)
	{
		head = head -> up2down;
		free (ptr);
		ptr = head;
	}
	free(ptr);
}

t_stack	*stack_extract(t_stack *head)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = head -> down2up;
	ptr2 = head -> up2down;
	ptr -> up2down = ptr2;
	ptr2 -> down2up = ptr;
	head -> up2down = NULL;
	head -> down2up = NULL;
	return (ptr2);
}

int	stack_count(t_stack *head)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = head;
	if (ptr)
		i++;
	ptr = ptr -> up2down;
	while (ptr != head)
	{
		i++;
		ptr = ptr -> up2down;
	}
	return (i);
}
