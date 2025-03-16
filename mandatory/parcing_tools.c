/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:48:10 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/16 17:11:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_big_box  	*box_struct(t_big_box *head)
{
	t_stack_a   *node_a;
	t_stack_b	*node_b;

	head = (t_big_box *)malloc(sizeof(t_big_box));
	if (!head)
		return (perror("Error\n"), NULL);
	node_a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!node_a)
		return (free(head), perror("Error\n"), NULL);
	node_a->content = 0;
	node_a->next = NULL;
	head->stack_a_head = node_a;
	node_b = (t_stack_b *)malloc(sizeof(t_stack_b));
	if (!node_b)
	return (free(node_a), perror("Error\n"), NULL);
	node_a->next = NULL;
	node_b->content = 0;
	head->stack_b_head = node_b;
	return (head);
}

void	ft_skip_space(const char *str, size_t *i)
{
	while (str[*i] == ' ' && str[*i])
		(*i)++;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	dup_check_helper(t_stack_a *head, int content)
{
	t_stack_a	*tmp;

	tmp = head;
	while (tmp && !tmp->next)
	{
		if (content == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	dup_check(t_big_box *box)
{
	int	tmp_cont;
	t_stack_a	*tmp;

	tmp = box->stack_a_head;
	while (tmp && tmp->next)
	{
		tmp_cont = tmp->content;
		printf("cont = %d\n", tmp_cont);
		if (dup_check_helper(box->stack_a_head, tmp_cont))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
