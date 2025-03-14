/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:19:49 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/14 15:39:23 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign(const char *str, size_t i, int *sign)
{
	*sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		return (1);
	}
	else
		return (error_throw(), 0);
	return (0);
}

static int	ft_checklong(size_t counter, long long nbr, int sign)
{
	if (nbr > LL_MAX || (sign == 1 && counter >= 20))
		return (-1);
	else if (nbr - 1 > LL_MAX || (sign == -1 && counter >= 20))
		return (0);
	return (1);
}

static int	ft_space_sign(char *str, size_t *i, int *sign)
{
	while (str[*i] == ' ')
		*i++;
	if (ft_sign(str, i, sign))
		*i++;
	while (str[*i] == '0')
		*i++;
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	nbr;
	size_t		counter;

	i = 0;
	nbr = 0;
	counter = 0;
	while (str[i] >= '0' && str[i] <= '9' || str[i] == ' ')
	{
		if (str[i] == ' ')
			i = ft_skip_space(str, i);
		nbr *= 10;
		nbr += str[i] - 48;
		counter++;
		if (ft_checklong(counter, nbr, sign) <= 0)
			return (ft_checklong(counter, nbr, sign));
		i++;
	}
	return ((int)nbr * sign);
}

int arguments_checker(char **str)
{
	int			i;
	t_stack_a	*a;

	a = (t_stack_a *)if (str[i] == '-')
	*sign = -1;
	while (str[i])
	{
		/* code */
	}
	
}

void	error_throw(void)
{
	perror("Error\n");
	exit(1);
}