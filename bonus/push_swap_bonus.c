/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/28 17:02:25 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	finished(t_big_box *big_box, int sign)
{
	ft_lstclear_stack_a(&(big_box->stack_a_head));
	ft_lstclear_stack_b(&(big_box->stack_b_head));
	free(big_box->joined);
	free(big_box);
	if (sign)
		exit(1);
	else
		exit(0);
}

void	printf_list(t_big_box *box)
{
	int	i;
	t_stack_a	*tmp;

	i = 0;
	tmp = box->stack_a_head;
	while (tmp)
	{
		printf("content = %llu, index = %d, rank in loop = %d\n", tmp->content, tmp->index, i);
		i++;
		tmp = tmp->next;
	}
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

// static void	ft_decide(t_big_box *b)
// {
// 	int	size;

// 	size = ft_lstsize_a(b->stack_a_head);
// 	if (size == 3)
// 		sort_three(b);
// 	else if (size > 3 && size <= 5)
// 		sort_four_or_five(b);
// 	else
// 		ft_big(&(b->stack_a_head), &(b->stack_b_head), get_range(&(b->stack_a_head)));
// }

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
	free(commands);
	finished(b, 1);
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
	// index_all(b->stack_a_head);
	if (dup_check(b))
		return (perror("Error\n"), 1);
	reading_operations(b);
	// ranking_index(b->stack_a_head);
	// ft_decide(b);
	puts("wslna lhna\n");
	printf("ha joined%s\n", b->joined);
	return (finished(b, 0), 0);
}
