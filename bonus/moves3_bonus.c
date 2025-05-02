/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:11:57 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:31:24 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}

void	ft_add_content(t_stack_a **head, int content)
{
	t_stack_a	*a;

	a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!a)
		return ;
	a->content = content;
	a->next = NULL;
	ft_lstadd_back_a(head, a);
}
