/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:15 by aumoreno          #+#    #+#             */
/*   Updated: 2024/06/22 10:27:38 by aumoreno         ###   ########.fr       */
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

/*UTILITIES FOR OUR STACKS*/
t_list *ft_insert_initial(char *args[], int index);
t_list *ft_lstnew(void *content);
void ft_lstclear(t_list **lst, void (*del)(void *));
int ft_lstsize(t_list *lst);
void ft_print_list(t_list *numbers);


/*GENERAL UTILS*/
int ft_strcmp(char *s1, char *s2);
void ft_free_arr(char **arr);


/*ERROR HANDLING*/
void ft_error_checking(t_list *lst);
void ft_error_handling(t_list *lst);
int ft_check_duplicates(t_list *lst);
int ft_isint(char *n);
void ft_error();

