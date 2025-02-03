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