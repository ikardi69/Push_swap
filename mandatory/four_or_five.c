/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_or_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:43:04 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/28 23:50:12 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void 	pushing_to_b(t_stack_a **stack_a, int position,  int size)
{
	int	i;

	if (position <= (size / 2))
	{
		i = -1;
		while (++i < position)
			ra(stack_a, 1);
	}
	else
	{
		i = -1;
		while (++i < (size - position))
		{
			rra(stack_a, 1);
		}
	}
}

void	push_two_smallest(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_a  	*current;
	int			i;
	int			position;
	int			size;
	int			smallest;

	current = *stack_a;
	smallest = current->content;
	position = 0;
	i = -1;
	size = ft_lstsize_a(*stack_a);
	while (++i < size)
	{
		if (current->content < smallest)
		{
			smallest = current->content;
			position = i;
		}
		current = current->next;
	}
	pushing_to_b(stack_a, position, size);
	pb(stack_a, stack_b);
}

void	sort_four_or_five(t_big_box *big_box)
{
	int size;

	push_two_smallest(&(big_box->stack_a_head), &(big_box->stack_b_head));
	push_two_smallest(&(big_box->stack_a_head), &(big_box->stack_b_head));
	size = ft_lstsize_a(big_box->stack_a_head);
	if (size == 3)
		sort_three(big_box);
	else if (size == 2)
	{
		if (big_box->stack_a_head->content > big_box->stack_a_head->next->content)
			sa(&(big_box->stack_a_head), 1);
	}
	size = ft_lstsize_b(big_box->stack_b_head);
	if (size == 2 && big_box->stack_b_head->content < big_box->stack_b_head->next->content)
		sb(&(big_box->stack_b_head), 1);
	while (big_box->stack_b_head)
		pa(&(big_box->stack_a_head), &(big_box->stack_b_head));
}
