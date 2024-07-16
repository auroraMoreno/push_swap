/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:26:40 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/16 02:14:16 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_first_case(t_list **a, t_list **b)
{
    //since we are not using b:
    (void)b;
    
    ft_swap_a(*a);  // aqui cuidado con printing letras 
    if(ft_issorted(*a))
        return ; //CHECK FOR PRINTING THE LETTER
    ft_swap_a(*a);
    ft_rotate_a(*a);
    
}

// 2,8,6
void ft_second_case(t_list **a, t_list **b)
{
    //could also be swap + reverse but this is better bc less movements 
    (void)b;
    ft_reverse_rotate_a(*a);
    if(!ft_issorted(*a))
        ft_swap_a(*a);
}

// this is the second case
void ft_third_case(t_list **a, t_list **b)
{
        (void)b;
        ft_rotate_a(*a);
        ft_swap_a(*a);
}


void ft_sort_three(t_list **a, t_list **b)
{

    char *first;
    char *second;
    char *third; 
    
    //check if it's sorted
    if(ft_issorted(*a))
        return ; 

    first = (*a)->value;
    second = (*a)->next->value;
    third = (*a)->next->next->value;
    

    // three possible cases: 
    // 6,2,8 
    if((ft_atoi(first) > ft_atoi(second)) && (ft_atoi(second) < ft_atoi(third)))
    {
        ft_first_case(a,b);
        return ;
    }
    // 2,8,6
    if((ft_atoi(first) < ft_atoi(second)) && (ft_atoi(second) > ft_atoi(third)))
    {
        ft_second_case(a,b);
        return;
    }
    // 8,6,2
    ft_third_case(a,b);
    return ;
    
}
