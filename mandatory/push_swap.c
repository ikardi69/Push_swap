/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/15 16:06:54 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	// t_big_box	*b;

	if (argc < 2)
		return (perror("Error\n"), 1);
	if ((arguments_checker(argv)) == 0)
		return (perror("Error\n"), 1);
	else
		return (printf("nice\n"), 0);
	return (0);
	// b = box_struct(b);
	// if (!b)
	// 	return (1);
}
