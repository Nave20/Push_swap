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

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack *head_b;
	t_stack *ptr;

	head_b = NULL;
	if (!argv[1])
		return (ft_printf("error\n"));
	head_a = new_stack(argv);
	if (stack_no_rep(head_a) != 1)
		return (stack_killer(head_a), ft_printf("error\n"));
	if (checker(head_a) == 1)
		return (stack_killer(head_a), 0);
	head_b = push(&head_a, head_b);
	head_b = push(&head_a, head_b);
	head_b = push(&head_a, head_b);
	head_b = push(&head_a, head_b);
	target(head_a, head_b);
	ptr = head_a;
	ft_printf("to head -> %d\n", ptr -> to_head);
	printer(head_a);
	ft_printf("\n\n");
	printer(head_b);
	stack_killer(head_a);
	stack_killer(head_b);
	return (0);
}