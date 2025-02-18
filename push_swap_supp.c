/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_supp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:11:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/18 16:11:36 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_isdigit(long c)
{
	if (c < 48 || c > 57)
		return (0);
	return (1);
}

int	numbers_only_b(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) != 1 && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_stack	*atoi_checker(char *arg, t_stack *node)
{
	int		nbr;
	t_stack	*head;
	int		bool;

	bool = 1;
	nbr = (int)ft_atoi(arg, &bool);
	if (bool == -1)
		return (NULL);
	head = next_up(nbr, node);
	if (!head)
		return (NULL);
	return (head);
}
