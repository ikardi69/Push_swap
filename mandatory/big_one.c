/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:26:52 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/26 13:50:25 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big_index(t_stack_b *stack_b)
{
	t_stack_b	*current;
	t_stack_b	*bigges_node;

	if (!stack_b)
		return (-1);
	current = stack_b;
	bigges_node = current;
	while (current)
	{
		if (current->index > bigges_node->index)
			bigges_node = current;
		current = current->next;
	}
	return (bigges_node->index);
}

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

void	ft_big(t_stack_a **stack_a, t_stack_b **stack_b, int range)
{
	int			i;

	i = 0;
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
		else if (check_ops(*stack_a))
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
