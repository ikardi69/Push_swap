/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:26:52 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:40:05 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_stack_b *stack_b, int max)
{
	int	posistion;

	posistion = 0;
	while (stack_b)
	{
		if (stack_b->index == max)
			return (posistion);
		stack_b = stack_b->next;
		posistion++;
	}
	return (-1);
}

void	final_s(t_stack_a **stack_a, t_stack_b **stack_b)
{
	int			max;
	t_stack_b	*tmp_b;

	while (*stack_b)
	{
		max = find_big_index(*stack_b);
		tmp_b = *stack_b;
		if (tmp_b->index == max)
			pa(stack_a, stack_b);
		else if (tmp_b->next && tmp_b->next->index == max)
		{
			sb(stack_b, 1);
			pa(stack_a, stack_b);
		}
		else
		{
			if (find_max_position(*stack_b, max)
				<= (ft_lstsize_b(*stack_b) / 2))
				rb(stack_b, 1);
			else
				rrb(stack_b, 1);
		}
	}
}

int	is_two_part_reverse_sorted(t_stack_a *stack)
{
	t_stack_a	*current;
	int			prev_val;
	int			has_decreasing_break;

	if (!stack || !stack->next)
		return (0);
	current = stack;
	prev_val = current->content;
	current = current->next;
	has_decreasing_break = 0;
	while (current)
	{
		if (prev_val <= current->content)
		{
			if (has_decreasing_break)
				return (0);
			has_decreasing_break = 1;
		}
		prev_val = current->content;
		current = current->next;
	}
	return (has_decreasing_break);
}

void	ft_big(t_stack_a **stack_a, t_stack_b **stack_b, int range)
{
	int	i;
	int	flags;

	i = 0;
	flags = is_two_part_reverse_sorted(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
			i++;
		}
		else if (flags && check_ops(*stack_a))
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	final_s(stack_a, stack_b);
}

int	check_ops(t_stack_a *a)
{
	int	count;
	int	diff;

	diff = 0;
	count = 0;
	while (a && a->next)
	{
		diff = a->index - a->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		a = a->next;
	}
	if (count * 10 >= (ft_lstsize_a(a) * 6))
		return (1);
	return (0);
}
