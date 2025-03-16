/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/16 17:19:29 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (dup_check(b))	//dup func debuging it doesnt enter to this function at all
		return (perror("Error\n"), 1);
	else
		return (printf("nice\n"), 0);
}
