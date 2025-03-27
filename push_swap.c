/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:21:45 by vpirotti          #+#    #+#             */
/*   Updated: 2025/01/31 12:21:45 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	error(t_stack *head)
{
	stack_killer(head);
	write(2, "Error\n", 6);
}

void	two_three(t_stack *head)
{
	if (stack_count(head) == 2)
	{
		ra(&head);
		stack_killer(head);
	}
	else if (stack_count(head) == 3)
	{
		solve_3(head);
		stack_killer(head);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_b = NULL;
	argc = 0;
	if (!argv[1])
		return ((int) write(2, "Error\n", 6));
	head_a = enter(argv);
	if (head_a == NULL)
		return ((int) write(2, "Error\n", 6));
	if (stack_no_rep(head_a) != 1)
		return (error(head_a), 0);
	if (checker(head_a) == 1)
		return (stack_killer(head_a), 0);
	if (stack_count(head_a) == 3 || stack_count(head_a) == 5)
	{
		two_three(head_a);
		return (0);
	}
	solver(&head_a, &head_b);
	stack_killer(head_a);
	return (0);
}
