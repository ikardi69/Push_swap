/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:31 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/21 15:22:56 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_a **stack_a)
{
	t_stack_a   *first;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	ft_lstadd_back(stack_a, first);
	ft_putstr("ra\n");
}

void	rb(t_stack_b **stack_b)
{
	t_stack_b	*first;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	ft_lstadd_back(stack_b, first);
	ft_putstr("rb\n");
}

void	rr(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next ||
		!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	ra(stack_a);
	rb(stack_b);
	ft_putstr("rr\n");
}

void	rra(t_stack_a **stack_a)
{
	t_stack_a	*last;
	t_stack_a	*second_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_a;
	second_last->next = NULL;
	*stack_a = last;
	ft_putstr("rra\n");
}

void	rrb(t_stack_b **stack_b)
{
	t_stack_b	*last;
	t_stack_b	*second_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack_b;
	second_last->next = NULL;
	*stack_b = last;
	ft_putstr("rrb\n");
}

void	rrr(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next ||
		!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rra(stack_a);
	rrb(stack_b);
	ft_putstr("rrr\n");
}
