/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movest_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:50:09 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/21 12:50:24 by mteffahi         ###   ########.fr       */
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
