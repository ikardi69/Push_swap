/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:11:57 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/21 18:12:21 by mteffahi         ###   ########.fr       */
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
