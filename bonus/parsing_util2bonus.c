/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util2bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:25:18 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/28 14:28:17 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void    extract_alt(char **str, t_stack_a **box_a, t_big_box *big_box)
{
    int tmp;
    int i;

    i = -1;
    while (str[++i])
    {
        tmp = ft_atoi(str[i], big_box);
        ft_add_content(box_a, tmp);
    }
    free_arr_ptr(str);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen(s) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	ft_memcpy(result, s, ft_strlen(s));
	result[ft_strlen(s)] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_lstsize_a(t_stack_a *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_lstsize_b(t_stack_b *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
