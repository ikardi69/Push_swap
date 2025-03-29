/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/29 16:49:46 by mteffahi         ###   ########.fr       */
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
	finished(b, 1);
}

void	reading_operations(t_big_box *big_box)
{
	char	*commands;

	commands = NULL;
	while ((commands = get_next_line(0)))
	{
		ft_check_moves(commands, big_box);
		big_box->joined = ft_strjoin(big_box->joined, commands);
		if (!big_box->joined)
			finished(big_box, 1);
		free(commands);
	}
	setup_opperations(big_box);
}

int main(int argc, char **argv)
{
	t_big_box	*b;
	
	b = NULL;
	if (argc < 2)
		return (0);
	if ((arguments_checker(argv)) == 0)
		return (perror("Error\n"), 1);
	b = box_struct(b);
	set_stack_a(b, argv);
	if (dup_check(b))
		return (perror("Error\n"), 1);
	reading_operations(b);
	return (finished(b, 0), 0);
}
