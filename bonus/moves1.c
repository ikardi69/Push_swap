/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:52:26 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/28 15:52:42 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	sb(t_stack_b **stack_b)
{
	t_stack_b	*first;
	t_stack_b	*second;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
}

void	ss(t_stack_a **stack_a, t_stack_b **stack_b)
{
	sa(stack_a);
	sb(stack_b);;
}

void	pa(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_b	*b_first;

	if (!stack_b || !*stack_b)
		return ;
	b_first = *stack_b;
	*stack_b = b_first->next;
	b_first->next = (t_stack_b *)*stack_a;
	*stack_a = (t_stack_a *)b_first;
}

void	pb(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_a	*a_first;

	if (!stack_a || !*stack_a)
		return ;
	a_first = *stack_a;
	*stack_a = a_first->next;
	a_first->next = (t_stack_a *)*stack_b;
	*stack_b = (t_stack_b *)a_first;
}