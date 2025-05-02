/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:28:08 by mteffahi         ###   ########.fr       */
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

int	get_range(t_stack_a **stack_a)
{
	int	size;

	size = ft_lstsize_a(*stack_a);
	if (size <= 100)
		return (size / 15);
	else
		return (size / 7);
}

void	sort_two(t_big_box *box)
{
	int	first;
	int	second;

	first = box->stack_a_head->content;
	second = box->stack_a_head->next->content;
	if (first > second)
		ra(&(box->stack_a_head), 1);
}

static void	ft_decide(t_big_box *b)
{
	int	size;

	size = ft_lstsize_a(b->stack_a_head);
	if (size == 2)
		sort_two(b);
	else if (size == 3)
		sort_three(b);
	else if (size > 3 && size <= 5)
		sort_four_or_five(b);
	else
		ft_big(&(b->stack_a_head), &(b->stack_b_head),
			get_range(&(b->stack_a_head)));
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
	if (ft_lstsize_a(b->stack_a_head) == 1)
		return (finished(b, 0), 0);
	index_all(b->stack_a_head);
	if (dup_check(b))
		return (write(2, "Error\n", 6), finished(b, 0), 1);
	sorted_check(b);
	ranking_index(b->stack_a_head);
	ft_decide(b);
	return (finished(b, 0), 0);
}
