/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/28 17:02:28 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finished(t_big_box *big_box, int sign)
{
	ft_lstclear_stack_a(&(big_box->stack_a_head));
	ft_lstclear_stack_b(&(big_box->stack_b_head));
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

static void	ft_decide(t_big_box *b)
{
	int	size;

	size = ft_lstsize_a(b->stack_a_head);
	if (size == 3)
		sort_three(b);
	else if (size > 3 && size <= 5)
		sort_four_or_five(b);
	else
		ft_big(&(b->stack_a_head), &(b->stack_b_head), get_range(&(b->stack_a_head)));
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
	index_all(b->stack_a_head);
	if (dup_check(b))
		return (perror("Error\n"), 1);
	ranking_index(b->stack_a_head);
	ft_decide(b);
	return (finished(b, 0), 0);
}
