/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:58:57 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/21 17:56:14 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_check(t_big_box *box)
{
	t_stack_a	*current;
	t_stack_a	*runner;

	current = box->stack_a_head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->content == runner->content)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_lstclear_stack_a(t_stack_a **lst)
{
	t_stack_a	*temp;

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
