/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/17 16:28:27 by mteffahi         ###   ########.fr       */
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
		printf("content = %d rank is = %d\n", tmp->content, i);
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
	printf_list(b);
	if (dup_check(b))
		return (perror("Error dyal duop\n"), 1);
	else
		return (printf("nice\n"), 0);
}
