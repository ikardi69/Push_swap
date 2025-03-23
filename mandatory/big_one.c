/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:26:52 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/23 17:12:53 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printf_list_lhad_zab(t_stack_a *stack_a)
{
	int	i;
	t_stack_a	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		printf("content = %llu, index = %d, rank in loop = %d\n", tmp->content, tmp->index, i);
		i++;
		tmp = tmp->next;
	}
}

static int	find_l_i_p(t_stack_a *stack_a)
{
	int	max_pos;
	int	i;
	int	max_in;

	max_pos = 0;
	i = 0;
	max_in = -1;
	while (stack_a)
	{
		if (stack_a->index > max_in)
		{
			max_in = stack_a->index;
			max_pos = i;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (max_in);
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
			++i;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
			++i;
		}
		else
			ra(stack_a, 1);
	}
	printf_list_lhad_zab(*stack_a);
}
