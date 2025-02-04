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
	t_stack	*head_A;
	t_stack *head_B;
	t_stack *ptr;

	head_B = NULL;
	if (!argv[1])
		return (ft_printf("error\n"));
	head_A = new_stack(argv);
	if (stack_no_rep(head_A) != 1)
		return (stack_killer(head_A), ft_printf("error\n"));
	if (checker(head_A) == 1)
		return (stack_killer(head_A), 0);
	head_B = push(&head_A, head_B);
	head_B = push(&head_A, head_B);
	head_B = push(&head_A, head_B);
	head_B = push(&head_A, head_B);
	target_min(head_A, head_B);
	ptr = head_A ->up2down;
	ft_printf("\n%d", ptr -> content);
	ptr = ptr -> target;
	ft_printf("-> %d \n\n", ptr -> content);
	printer(head_A);
	ft_printf("\n\n");
	printer(head_B);
	stack_killer(head_A);
	stack_killer(head_B);
	return (0);
}