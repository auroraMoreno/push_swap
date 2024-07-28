/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:15 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 19:07:09 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}	t_list;
int		main(int argc, char **argv);
void	ft_first_case(t_list **a, t_list **b);
void	ft_second_case(t_list **a, t_list **b);
void	ft_third_case(t_list **a, t_list **b);
void	ft_sort_three(t_list **a, t_list **b);
void	ft_sort_four(t_list **a, t_list **b);
void	ft_sort_five(t_list **a, t_list **b);
void	ft_do_alg(t_list **a, t_list **b);
void	ft_move_to_a(t_list **a, t_list **b);
int		ft_move_to_b(t_list **a, t_list **b, int *chunks);
int		ft_chunk_has_elements(t_list *a, int i, int *chunks);
void	ft_chunk_has_elements_test(t_list **a, t_list **b, int *chunks);
int		*ft_generate_segments(t_list *lst);
int		ft_is_in_range(int n, int i, int *chunks);
int		ft_get_max_pos(t_list *lst);
int		ft_get_min_value(t_list *a);
int		ft_get_max_value(t_list *lst);
int		ft_get_max_pos(t_list *lst);
void	ft_rotate_list(int *top_pos, int *bottom_pos, t_list **b);
t_list	*ft_insert_initial(char *args[], int index);
t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
void	ft_print_list(t_list *numbers);
void	ft_lst_del_elment(t_list *el, void (*del)(void *));
int		ft_issorted(t_list *numbers);
void	ft_insert_first(t_list **lst, t_list *new_value);
void	ft_push(t_list **dest, t_list **src, int insert_next);
void	ft_pa(t_list **a, t_list **b, int insert_next);
void	ft_pb(t_list **a, t_list **b, int insert_next);
void	ft_swap_a(t_list *a);
void	ft_swap_b(t_list *b);
void	ft_ss(t_list *a, t_list *b);
void	ft_rotate(t_list *lst);
void	ft_rotate_a(t_list *a);
void	ft_rotate_b(t_list *b);
void	ft_rr(t_list *a, t_list *b);
t_list	*ft_get_last(t_list *lst);
void	ft_reserve_rotate(t_list *lst);
void	ft_reverse_rotate_a(t_list *a);
void	ft_reverse_rotate_b(t_list *b);
void	ft_rrr(t_list *a, t_list *b);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_arr(char **arr);
void	ft_select_alg(t_list **a, t_list **b);
void	ft_error_checking(t_list *lst);
void	ft_error_handling(t_list *lst);
int		ft_check_duplicates(t_list *lst);
int		ft_isint(char *n);
void	ft_error(void);