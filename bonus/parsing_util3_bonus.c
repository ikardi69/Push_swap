/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:53:49 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/23 17:55:46 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstclear_stack_b(t_stack_b **lst)
{
	t_stack_b	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	free_arr_ptr(char **str)
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
