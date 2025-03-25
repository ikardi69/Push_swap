/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:26:52 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/25 14:17:14 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	printf_list_lhad_zab(t_stack_a *stack_a, t_stack_b *stack_b)
// {
// 	int	i;
// 	t_stack_a	*tmp_a;
// 	t_stack_b	*tmp_b;

// 	i = 0;
// 	tmp_a = stack_a;
// 	tmp_b = stack_b;
// 	puts("stack_a :\n");
// 	while (tmp_a)
// 	{
// 		printf("content = %llu, index = %d, rank in loop = %d\n", tmp_a->content, tmp_a->index, i);
// 		i++;
// 		tmp_a = tmp_a->next;
// 	}
// 	i = 0;
// 	puts("stack_b :\n");
// 	while (tmp_b)
// 	{
// 		printf("content = %llu, index = %d, rank in loop = %d\n", tmp_b->content, tmp_b->index, i);
// 		i++;
// 		tmp_b = tmp_b->next;
// 	}
// }

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
	int	max;
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
			if (find_max_position(*stack_b, max) <= (ft_lstsize_b(*stack_b) / 2))
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
		else
			ra(stack_a, 1);
	}
	final_s(stack_a, stack_b);
	// printf_list_lhad_zab(*stack_a, *stack_b);
}
