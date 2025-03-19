/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/19 15:48:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(int argc, char **argv)
{
	t_big_box	*b;

	b = NULL;
	if (argc < 2)
		return (perror("Error\n"), 1);
	if ((arguments_checker(argv)) == 0)
		return (perror("Error\n"), 1);
	else
		printf("nice\n");
	b = box_struct(b);
	if (!b)
		return (perror("Error: Box struct failed\n"), 1);
	set_stack_a(b, argv);
	index_all(b->stack_a_head);
	printf_list(b);
	if (dup_check(b))
	return (perror("Error dyal duop\n"), 1);
	else
	printf("m9awd\n");
	ranking_index(b->stack_a_head);
	printf_list(b);
	// if (argc == 3)
}
