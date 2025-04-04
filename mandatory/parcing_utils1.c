/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:32:23 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/31 13:16:46 by mteffahi         ###   ########.fr       */
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

int arguments_checker(char **str)
{
	int	i;
	int	x;

	x = 0;
	while (str[++x])
	{
		i = -1;
		while (str[x][++i])
		{
			if (( i != 0 && str[x][i - 1] != ' ') && str[x][i] == '-')
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
	t_stack_a *a;

	a = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!a)
		return ;
	a->content = content;
	a->next = NULL;
	ft_lstadd_back_a(head, a);
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

void		free_arr_ptr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str);
}

void	ft_lstadd_back_a(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*tmp;

	if (!new || !lst)
		return ;
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_lstadd_back_b(t_stack_b **lst, t_stack_b *new)
{
	t_stack_b	*tmp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
