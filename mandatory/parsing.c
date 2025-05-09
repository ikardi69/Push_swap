/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:19:49 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/26 16:02:11 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sign(const char *str, size_t i, int *sign, t_big_box *big_box)
{
	*sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		return (1);
	}
	else if (str[i] >= '0' && str[i] <= '9')
		return (0);
	else
		return (finished(big_box, 1), 0);
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

static void	ft_space_sign(const char *str, size_t *i,
					int *sign, t_big_box *big_box)
{
	while (str[*i] == ' ' && str[*i])
		(*i)++;
	if (str[*i] && ft_sign(str, *i, sign, big_box))
		(*i)++;
	while (str[*i] == '0' && str[*i])
		(*i)++;
}

int	ft_atoi(const char *str, t_big_box *big_box)
{
	size_t		i;
	int			sign;
	long long	nbr;
	size_t		counter;

	i = 0;
	nbr = 0;
	counter = 0;
	ft_space_sign(str, &i, &sign, big_box);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
	{
		if (str[i] == ' ')
			ft_skip_space(str, &i);
		nbr *= 10;
		nbr += str[i] - 48;
		counter++;
		if (ft_checklong(counter, nbr, sign) <= 0)
			return (write(2, "Error\n", 6), finished(big_box, 1),
				ft_checklong(counter, nbr, sign));
		i++;
	}
	if (nbr > 2147483647)
		return (write(2, "Error\n", 6), finished(big_box, 1), 1);
	return ((int)nbr * sign);
}
