/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:48:10 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/27 23:24:38 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_big_box  	*box_struct(t_big_box *head)
{
	head = (t_big_box *)malloc(sizeof(t_big_box));
	if (!head)
		return (perror("Error\n"), exit(1), NULL);
	head->stack_a_head = NULL;
	head->stack_b_head = NULL;
	head->moves = NULL;
	head->joined = NULL;
	return (head);
}

void	ft_skip_space(const char *str, size_t *i)
{
	while (str[*i] == ' ' && str[*i])
		(*i)++;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

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
