/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:50:09 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:41:31 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack_b **stack_b, int sign)
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
	if (sign)
		ft_putstr("rrb\n");
}

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

void	set_stack_a(t_big_box *box, char **str)
{
	int				i;
	char			**temp;
	long long		tmp;

	i = 0;
	while (str[++i])
	{
		if (ft_space_check(str[i]))
		{
			temp = ft_split(str[i], ' ');
			if (!temp)
				return ;
			extract_alt(temp, &(box->stack_a_head), box);
		}
		else
		{
			tmp = ft_atoi(str[i], box);
			ft_add_content(&(box->stack_a_head), tmp);
		}
	}
}
