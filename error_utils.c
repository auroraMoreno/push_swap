/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:51:51 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/22 01:29:09 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_error_checking(t_list *lst)
{
    // checking if has more than 1 element / number
    // if it's 1 and IT'S A NUMBER EXIT SUCCES 
    // IF NOT F
    if(ft_lstsize(lst) == 1)
    {
        // check if that one element is a number 
        ft_error_handling(lst);
        exit(EXIT_SUCCESS);        
    }
    ft_error_handling(lst); //THIS PART DOESNT MAKE SENSE BUT WE'LL FIGURE IT OUT LATER
}

void ft_error_handling(t_list *lst)
{
    t_list *curr;

    //poner q mire si es un integer primero, es más óptimo 
    
    // check for duplicates 
    if(ft_check_duplicates(lst) ==  1) 
        ft_error();
    curr = lst;
    while(curr)
    {
        if(!ft_isint(curr->value) || ft_strlen(curr->value) < 1) //don't know if this really makes sense 
            ft_error();
        curr = curr->next;
    }
    
}

// don't think this will entirely work!! 
int ft_check_duplicates(t_list *lst)
{
    t_list *curr;
    t_list *next; 

    curr = lst;
    if(!curr)
        return (1); // return 1, lst being null will also be considered an eror 
    
    while(curr->next)
    {
        next = curr->next;
        while(next)
        {
            if(ft_strcmp(curr->value, next->value) == 0)
                return (1); 
            next = next->next;
        }  
        curr = curr->next; 
    }

    return(0);
}


int ft_isint(char *l)
{
    long n;
    long sign;
    int i; 
    
    n = 0;
    sign = 1; 
    i = 0;
    while(l[i] == ' ')
        i++;
    
    if(l[i] == '-' || l[i] == '+')
    {
        if(l[i] == '-')
            sign = -sign;
        i++;
    }

    while(ft_isdigit(l[i]))
    {
        n = (n * 10) + (l[i] - 48);
        if(n * sign > INT_MAX || n * sign < INT_MIN)
            return (0);
        i++;
    }
    while(l[i] == ' ')
        i++;
    
    return (l[i] == '\0');
    
}


void ft_error()
{
    ft_putendl_fd("Error\n",2);
    exit(EXIT_FAILURE);
}
