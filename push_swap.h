/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:15 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/18 22:29:42 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

//this is a doubly linked list 
typedef struct s_list
{
    void *value;
    struct s_list *next;
    
} t_list;

int main();

/*ALGORITHM*/
void ft_first_case(t_list **a, t_list **b);
void ft_second_case(t_list **a, t_list **b);
void ft_third_case(t_list **a, t_list **b);
void ft_sort_three(t_list **a, t_list **b);
void ft_sort_four(t_list **a, t_list **b);
int ft_get_min_value(t_list *a);

/*UTILITIES FOR OUR STACKS*/
t_list *ft_insert_initial(char *args[], int index);
t_list *ft_lstnew(void *content);
void ft_lstclear(t_list **lst, void (*del)(void *));
int ft_lstsize(t_list *lst);
void ft_print_list(t_list *numbers);
void ft_lst_del_elment(t_list *el, void (*del)(void *));
int ft_issorted(t_list *numbers); //cambiar esta de sitio 

/*OPERATIONS*/
/* push */
void ft_insert_first(t_list **lst, t_list *new_value);
void ft_push(t_list **dest, t_list **src);
void ft_pa(t_list  **a, t_list **b);
void ft_pb(t_list **a, t_list **b);
/* swap */
void ft_swap_a(t_list *a);
void ft_swap_b(t_list *b);
void ft_ss(t_list *a, t_list *b);

/* rotate */
void ft_rotate(t_list *lst);
void ft_rotate_a(t_list *a);
void ft_rotate_b(t_list *b);
void ft_rr(t_list *a, t_list *b); 


/* reverse rotating */
t_list *ft_get_last(t_list *lst);
void ft_reserve_rotate(t_list *lst);
void ft_reverse_rotate_a(t_list *a);
void ft_reverse_rotate_b(t_list *b);
void ft_rrr(t_list *a, t_list *b);


/*GENERAL UTILS*/
int ft_strcmp(char *s1, char *s2);
void ft_free_arr(char **arr);
void ft_select_alg(t_list **a, t_list **b);


/*ERROR HANDLING*/
void ft_error_checking(t_list *lst);
void ft_error_handling(t_list *lst);
int ft_check_duplicates(t_list *lst);
int ft_isint(char *n);
void ft_error();

