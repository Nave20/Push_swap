/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:17:55 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/14 11:33:15 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack *head)
{
	long	i;
	t_stack	*node;
	t_stack	*ptr;

	i = head -> content;
	ptr = head;
	node = head -> up2down;
	while (node != head)
	{
		if (i < node -> content)
		{
			i = node -> content;
			ptr = node;
		}
		node = node -> up2down;
	}
	return (ptr);
}

void	last_sort(t_stack **head_a)
{
	t_stack	*max;
	int		i;

	i = 0;
	max = find_max(*head_a);
	if (stack_index(*head_a, max) > (stack_count(*head_a) / 2))
	{
		while (checker(*head_a) != 1)
		{
			rra(head_a);
			i++;
			if (i == 2500)
				return;
		}
	}
	else
	{
		while (checker(*head_a) != 1)
		{
			ra(head_a);
			i++;
			if (i == 2500)
				return;
		}
	}
}

t_stack	*new_stack_2(char **argv)
{
	t_stack	*new;
	t_stack	*temp;
	t_stack	*next;
	int		i;

	i = 0;
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
