/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:00:49 by mteffahi          #+#    #+#             */
/*   Updated: 2025/03/22 16:00:20 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define LL_MAX 9223372036854775807LL
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_a
{
	long long			content;
	int					index;
	struct s_stack_a	*next; 
}t_stack_a;

typedef struct s_stack_b
{
	long long			content;
	int					index;
	struct s_stack_b	*next; 
}t_stack_b;

typedef struct s_big_box
{
	struct s_stack_a	*stack_a_head;
	struct s_stack_b	*stack_b_head;
}t_big_box;



int 		ft_atoi(const char *str);
void		error_throw(void);
int			arguments_checker(char **str);
t_big_box	*box_struct(t_big_box *head);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_skip_space(const char *str, size_t *i);
void		set_stack_a(t_big_box *box, char **str);
int			ft_space_check(char *str);
void		ft_free(t_big_box *box);
void		free_arr_ptr(char **str);
void		extract_alt(char **str, t_stack_a **box_a);
void		ft_lstadd_back_a(t_stack_a **lst, t_stack_a *new);
void		ft_lstadd_back_b(t_stack_b **lst, t_stack_b *new);
void		ft_add_content(t_stack_a **head, int content);
int			dup_check(t_big_box *box);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);

int			ft_lstsize_a(t_stack_a *lst);
int			ft_lstsize_b(t_stack_b *lst);

void		finished(t_big_box *big_box);

void		ft_lstclear_stack_a(t_stack_a **lst);
void		ft_lstclear_stack_b(t_stack_b **lst);
void		index_all(t_stack_a *stack_a);
void		ranking_index(t_stack_a *stack_a);
void		ft_putstr(char *str);
/* The operations*/ // we have a problem in printing the opersation if we use an operation that contain other operations
void		sa(t_stack_a **stack_a, int sign);
void		sb(t_stack_b **stack_b, int sign);
void		ss(t_stack_a **stack_a, t_stack_b **stack_b);
void		pa(t_stack_a **stack_a, t_stack_b **stack_b);
void		pb(t_stack_a **stack_a, t_stack_b **stack_b);
void		ra(t_stack_a **stack_a, int sign);
void		rb(t_stack_b **stack_b, int sign);
void		rr(t_stack_a **stack_a, t_stack_b **stack_b);
void		rra(t_stack_a **stack_a, int sign);
void		rrb(t_stack_b **stack_b, int sign);
void		rrr(t_stack_a **stack_a, t_stack_b **stack_b);
/************************************************************/
/*Sort Three*/
/************************************************************/
void		sort_three(t_big_box *big_box);
/************************************************************/
/*Sort four or five*/
/************************************************************/
void		push_two_smallest(t_stack_a **stack_a, t_stack_b **stack_b);
void		sort_four_or_five(t_big_box *big_box);
/************************************************************/
/*Sorting 100 or fewer numbers*/
/************************************************************/

#endif
