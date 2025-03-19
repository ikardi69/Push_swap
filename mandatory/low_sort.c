/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:25:29 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/19 16:55:55 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_all(t_stack_a *stack_a)
{
	t_stack_a  	*tmp;

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
			if (current->index == -1 && current->content < smallest_node->content)
				smallest_node = current;
			current = current->next;
		}
		smallest_node->index = current_index++;		
	}
}

void	sort_three(t_big_box *big_box)
{
	int			size;
	t_stack_a	*stack_a;

	size = ft_lstsize(&(big_box->stack_a_head));
	stack_a = big_box->stack_a_head;
	while (stack_a)
	{
		if (stack_a->index == size)
		{
			sa(&(big_box->stack_a_head));
			return ;
		}
	}
	
}
