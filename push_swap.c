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
		return (ft_printf("value ???"));
	head_A = new_stack(argv);
	if (stack_no_rep(head_A) != 1)
		return (stack_killer(head_A), ft_printf("Rep in stack\n"));
	printer(head_A);
	stack_killer(head_A);
	return (0);
}