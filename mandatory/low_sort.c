/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:29 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/21 12:47:21 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_all(t_stack_a *stack_a)
{
	t_stack_a	*tmp;

	tmp = stack_a;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

void	ranking_index(t_stack_a *stack_a)
{
	int			current_index;
	t_stack_a	*current;
	t_stack_a	*smallest_node;

	current_index = 0;
	while (1)
	{
		current = stack_a;
		smallest_node = NULL;
		while (current && current->index != -1)
			current = current->next;
		if (!current)
			break ;
		smallest_node = current;
		while (current)
		{
			if (current->index == -1
				&& current->content < smallest_node->content)
				smallest_node = current;
			current = current->next;
		}
		smallest_node->index = current_index++;
	}
}

void	sort_three(t_big_box *big_box)
{
	int	first;
	int	second;
	int	third;

	first = big_box->stack_a_head->index;
	second = big_box->stack_a_head->next->index;
	third = big_box->stack_a_head->next->next->index;
	if (first > second && first > third)
		ra(&big_box->stack_a_head, 1);
	else if (second > first && second > third)
		rra(&big_box->stack_a_head, 1);
	first = big_box->stack_a_head->index;
	second = big_box->stack_a_head->next->index;
	if (first > second)
		sa(&big_box->stack_a_head, 1);
}
