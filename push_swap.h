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

typedef struct s_stack
{
	long			content;
	int				cost;
	int				to_head;
	int				p_moves;
	int				n_moves;
	struct s_stack	*up2down;
	struct s_stack	*down2up;
	struct s_stack	*target;
}	t_stack;

int		ft_atoi(const char *str);
int		ft_printf(const char *s, ...);
long	ft_isdigit(long c);

t_stack	*new_stack(char **argv);
void	stack_killer(t_stack *head);
int		stack_count(t_stack *head);
t_stack	*stack_extract(t_stack *head);
void	stack_rounder(t_stack *head);

t_stack	*reverse_rotate(t_stack *head);
t_stack	*rotate(t_stack *head);
t_stack	*push(t_stack **head_a, t_stack *head_b);
t_stack	*swap(t_stack *head);

// void	printer(t_stack *head);
t_stack	*next_up(int content, t_stack *down2up);
int		stack_index(t_stack *head, t_stack *node);
int		checker(t_stack *head);
int		greatest(int a, int b);
void	moves_reset(t_stack *head_a);

t_stack	*solve_3(t_stack *head);
void	target(t_stack *head_a, t_stack *head_b);
void	target_min(t_stack *node_a, t_stack *head_b);
void	target_max(t_stack *node_a, t_stack *head_b);

int		stack_no_rep(t_stack *head);
int		numbers_only(char **argv);

void	to_head(t_stack *head_a);
void	cost(t_stack *head_a, t_stack *head_b);
void	cost_logic(t_stack *node_a);
t_stack	*to_move(t_stack *head_a);

void	ra(t_stack **head_a);
void	rb(t_stack **head_b);
void	rr(t_stack **head_a, t_stack **head_b);
void	rra(t_stack **head_a);
void	rrb(t_stack **head_b);

void	rrr(t_stack **head_a, t_stack **head_b);
void	sa(t_stack **head_a);
void	sb(t_stack **head_b);
void	ss(t_stack **head_a, t_stack **head_b);
void	pa(t_stack **head_a, t_stack **head_b);

void	pb(t_stack **head_a, t_stack **head_b);

int		up_or_down(t_stack *node_a);
void	solver(t_stack **head_a, t_stack **head_b);

void	n_move_b(t_stack *node_a, t_stack **head_a, t_stack **head_b);
void	p_move_b(t_stack *node_a, t_stack **head_a, t_stack **head_b);
void	mover_b(t_stack *node_a, t_stack **head_a, t_stack **head_b);
int		rev_checker(t_stack *head);

void	target_second(t_stack *head_a, t_stack *head_b);

void	last_sort(t_stack **head_a);

#endif