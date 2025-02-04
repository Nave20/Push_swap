/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 09:35:23 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/02 09:35:23 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_stack
{
	long			content;
	struct t_stack	*up2down;
	struct t_stack	*down2up;
	struct t_stack	*target;
}	t_stack;

int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);

t_stack	*new_stack(char **argv);
void	stack_killer(t_stack *head);
int		stack_count(t_stack *head);
t_stack	*stack_extract(t_stack *head);
void	stack_rounder(t_stack *head);

t_stack	*reverse_rotate(t_stack *head);
t_stack	*rotate(t_stack *head);
t_stack	*push(t_stack **head_a, t_stack *head_b);
t_stack *swap(t_stack *head);

void	printer(t_stack *head);
t_stack	*next_up(int content, t_stack *down2up);
int		checker(t_stack *head);

t_stack	*solve_3(t_stack *head);
void	target_min(t_stack *head_A, t_stack *head_B);
void	target_max(t_stack *node_a, t_stack *head_B);

int		stack_no_rep(t_stack *head);

#endif