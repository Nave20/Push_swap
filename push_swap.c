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

	head_B = NULL;
	if (!argv[1])
		return (ft_printf("value ???"));
	head_A = new_stack(argv);
	head_A = rotate(head_A);
	head_B = push(&head_A, head_B);
	head_A = swap(head_A);
	printer(head_A);
	ft_printf("\n");
	stack_rounder(head_B);
	printer(head_B);
	stack_killer(head_A);
	stack_killer(head_B);
	return (0);
}