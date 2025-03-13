/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:48:10 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/13 16:37:35 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_big_box  	*box_struct(t_big_box *head)
{
	t_stack_a   *node_a;
	t_stack_b	*node_b;

	head = (t_big_box *)malloc(sizeof(t_big_box));
	if (!head)
		return (error_throw(), NULL);
	node_a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!node_a)
		return (free(head), error_throw(), NULL);
	node_a->num = 0;
	head->stack_a_head = node_a;
	node_b = (t_stack_b *)malloc(sizeof(t_stack_b));
	if (!node_b)
	return (free(node_a), error_throw(), NULL);
	head->stack_b_head = node_b;
	node_b->num = 0;
	return (head);
}

int	ft_skip_space(char *str, int i)
{
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}
