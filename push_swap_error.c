/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:17:51 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/03 15:17:51 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_no_rep(t_stack *head)
{
	t_stack	*ptr;
	t_stack	*ptr2;

	ptr = head -> up2down;
	ptr2 = ptr -> up2down;
	while (ptr != head)
	{
		while (ptr2 != ptr)
		{
			if (ptr -> content == ptr2 -> content)
				return (0);
			ptr2 = ptr2 -> up2down;
		}
		ptr = ptr -> up2down;
	}
	return (1);
}

int	numbers_only(char **argv)
{
	int	i;
	int	j;

	i = 1;
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

t_stack	*enter(char **argv, int argc)
{
	t_stack	*head_a;

	if (argc == 2)
		head_a = spliter(argv);
	else
	{
		if (numbers_only(argv) != 1)
			return (NULL);
		head_a = new_stack(argv);
	}
	return (head_a);
}

static void	*ft_die(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

t_stack	*spliter(char **argv)
{
	char	**output;
	t_stack	*head_a;

	output = ft_split(argv[1], ' ');
	if (numbers_only(output) != 1)
	{
		return (NULL);
	}
	head_a = new_stack_2(output);
	ft_die(output);
	if (head_a == NULL)
		return (NULL);
	return (head_a);
}
