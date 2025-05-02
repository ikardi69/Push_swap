/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:46:51 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/02 18:19:52 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	apply_operations(t_big_box *big_box, char *operation)
{
	if (!ft_strcmp(operation, "sa\n"))
		sa(&(big_box->stack_a_head));
	else if (!ft_strcmp(operation, "sb\n"))
		sb(&(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "ss\n"))
		ss(&(big_box->stack_a_head), &(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "pa\n"))
		pa(&(big_box->stack_a_head), &(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "pb\n"))
		pb(&(big_box->stack_a_head), &(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "ra\n"))
		ra(&(big_box->stack_a_head));
	else if (!ft_strcmp(operation, "rb\n"))
		rb(&(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "rr\n"))
		rr(&(big_box->stack_a_head), &(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "rra\n"))
		rra(&(big_box->stack_a_head));
	else if (!ft_strcmp(operation, "rrb\n"))
		rrb(&(big_box->stack_b_head));
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(&(big_box->stack_a_head), &(big_box->stack_b_head));
}

void	setup_opperations(t_big_box *big_box)
{
	int	i;

	if (big_box->joined)
		big_box->moves = ft_split(big_box->joined, '\n');
	if (!big_box->moves)
		finished(big_box, 1);
	i = 0;
	while (big_box->moves[i])
	{
		apply_operations(big_box, big_box->moves[i]);
		i++;
	}
	final_check(big_box);
}

void	final_check(t_big_box *big_box)
{
	t_stack_a	*tmp;

	if (big_box->stack_b_head)
	{
		ft_putstr("KO\n");
		finished(big_box, 1);
	}
	tmp = big_box->stack_a_head;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			ft_putstr("KO\n");
			finished(big_box, 1);
		}
		tmp = tmp->next;
	}
	ft_putstr("OK\n");
	finished(big_box, 0);
}

int	sorted_check(t_big_box *box)
{
	t_stack_a	*tmp_a;

	tmp_a = box->stack_a_head;
	if (!tmp_a)
		return (0);
	while (tmp_a && tmp_a->next)
	{
		if (tmp_a->content > tmp_a->next->content)
			return (0);
		tmp_a = tmp_a->next;
	}
	ft_putstr("OK\n");
	finished(box, 0);
	return (1);
}

void	check_empty_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
