/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:32:23 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:32:56 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
			if (str[x][i] == '-' && (str[x][i - 1] != ' ' && i != 0))
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

void	set_stack_a(t_big_box *box, char **str)
{
	int				i;
	char			**temp;
	long long		tmp;

	i = 0;
	while (str[++i])
	{
		if (ft_space_check(str[i]))
		{
			temp = ft_split(str[i], ' ');
			if (!temp)
				return ;
			extract_alt(temp, &(box->stack_a_head), box);
		}
		else
		{
			tmp = ft_atoi(str[i], box);
			ft_add_content(&(box->stack_a_head), tmp);
		}
	}
}
