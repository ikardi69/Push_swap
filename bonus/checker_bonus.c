/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 12:55:23 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	finished(t_big_box *big_box, int sign)
{
	int	i;

	ft_lstclear_stack_a(&(big_box->stack_a_head));
	ft_lstclear_stack_b(&(big_box->stack_b_head));
	if (big_box->joined)
		free(big_box->joined);
	if (big_box->moves)
	{
		i = -1;
		while (big_box->moves[++i])
		{
			free(big_box->moves[i]);
		}
	}
	if (big_box->moves)
		free(big_box->moves);
	free(big_box);
	if (sign)
		exit(1);
	else
		exit(0);
}

int	get_range(t_stack_a **stack_a)
{
	int	size;

	size = ft_lstsize_a(*stack_a);
	if (size <= 100)
		return (13);
	else
		return (37);
}

void	ft_check_moves(char *commands, t_big_box *b)
{
	if (!ft_strcmp(commands, "sa\n"))
		return ;
	else if (!ft_strcmp(commands, "sb\n"))
		return ;
	else if (!ft_strcmp(commands, "ss\n"))
		return ;
	else if (!ft_strcmp(commands, "pa\n"))
		return ;
	else if (!ft_strcmp(commands, "pb\n"))
		return ;
	else if (!ft_strcmp(commands, "ra\n"))
		return ;
	else if (!ft_strcmp(commands, "rb\n"))
		return ;
	else if (!ft_strcmp(commands, "rr\n"))
		return ;
	else if (!ft_strcmp(commands, "rra\n"))
		return ;
	else if (!ft_strcmp(commands, "rrb\n"))
		return ;
	else if (!ft_strcmp(commands, "rrr\n"))
		return ;
	write(2, "Error\n", 6);
	finished(b, 0);
}

void	reading_operations(t_big_box *big_box)
{
	char	*commands;

	commands = NULL;
	while (1)
	{
		commands = get_next_line(0);
		if (!commands)
			break ;
		ft_check_moves(commands, big_box);
		big_box->joined = ft_strjoin(big_box->joined, commands);
		if (!big_box->joined)
			finished(big_box, 1);
		free(commands);
	}
	if (ft_lstsize_a(big_box->stack_a_head) > 1)
		sorted_check(big_box);
	setup_opperations(big_box);
}

int	main(int argc, char **argv)
{
	t_big_box	*b;

	(void)argc;
	b = NULL;
	if ((arguments_checker(argv)) == 0)
		return (write(2, "Error\n", 6), 1);
	check_empty_args(argv);
	b = box_struct(b);
	set_stack_a(b, argv);
	if (dup_check(b))
		return (write(2, "Error\n", 6), finished(b, 1), 1);
	reading_operations(b);
	if (ft_lstsize_a(b->stack_a_head) == 1)
		return (finished(b, 0), 0);
	if (!sorted_check(b))
		return (ft_putstr("KO\n"), finished(b, 1), 1);
	else
		return (ft_putstr("OK\n"), finished(b, 0), 1);
	return (finished(b, 0), 0);
}
