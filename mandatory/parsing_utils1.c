/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:32:23 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:41:28 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(int c)
{
	if (c == ' ')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (!(ft_isdigit(c)))
		return (1);
	else
		return (0);
}

static int	check_number(int c)
{
	if (c == ' ')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	return (0);
}

int	arguments_checker(char **str)
{
	int	i;
	int	x;

	x = 0;
	while (str[++x])
	{
		i = -1;
		while (str[x][++i])
		{
			if ((check_number(str[x][i])) == 0)
				return (0);
			if ((i != 0 && str[x][i - 1] != ' ')
				&& (str[x][i] == '-' || str[x][i] == '+'))
				return (0);
			else if (str[x][i + 1] == '\0')
			{
				if ((check(str[x][i])))
					return (0);
			}
		}
	}
	return (1);
}

int	ft_space_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}

void	ft_add_content(t_stack_a **head, int content)
{
	t_stack_a	*a;

	a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!a)
		return ;
	a->content = content;
	a->next = NULL;
	ft_lstadd_back_a(head, a);
}
