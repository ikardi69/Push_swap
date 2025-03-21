/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:02:02 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/21 14:42:29 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_a **stack_a)
{
	t_stack_a	*first;
	t_stack_a	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	ft_putstr("sa\n");
}

void	sb(t_stack_b **stack_b)
{
	t_stack_a	*first;
	t_stack_a	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	ft_putstr("sb\n");
}

void	ss(t_stack_a **stack_a, t_stack_b **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr("ss\n");
}

void	pa(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_b	*b_first;

	if (!stack_b || !*stack_b)
		return ;
	b_first = *stack_b;
	*stack_b = b_first->next;
	b_first->next = *stack_a;
	*stack_a = b_first;
	ft_putstr("pa\n");
}

void	pb(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_a	*a_first;

	if (!stack_a || !*stack_a)
		return ;
	a_first = *stack_a;
	*stack_a = a_first->next;
	a_first->next = *stack_b;
	*stack_b = a_first;
	ft_putstr("pb\n");
}
