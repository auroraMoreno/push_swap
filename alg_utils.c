/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:19:12 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/22 00:05:45 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_select_alg(t_list **a, t_list **b)
{
    // for 2,3,4,5
    //list size loops!! we pass the first node and count from there 
    if(ft_lstsize(*a) == 2)
        ft_swap_a(*a);
    else if(ft_lstsize(*a) == 3)
        ft_sort_three(a,b);
    else if(ft_lstsize(*a) == 4)
        ft_sort_four(a,b);
    else if(ft_lstsize(*a) == 5)
        ft_sort_five(a,b);
    else
        ft_do_alg(a,b);
    
}

int ft_is_in_range(int n, int i, int *chunks)
{
    return ((n >= chunks[i] && n < chunks[i + 1]));
}


int ft_get_max_pos(t_list *lst)
{
    t_list *curr; 
    int max_value;
    int max_pos;
    int i;

    curr = lst;
    max_value = ft_atoi(curr->value);
    max_pos = 0; 
    i = 0;
    while(curr)
    {
        if(ft_atoi(curr->value) > max_value)
        {
            max_pos = i;
            max_value = ft_atoi(curr->value);
        }
        curr = curr->next;
        i++;
    }

    return (max_pos);
    
}

int ft_get_max_value(t_list *lst)
{
    int max;
    t_list *curr; 

    max = ft_atoi(lst->value);
    curr = lst; 
    while(curr)
    {
        if(ft_atoi(curr->value) > max)
            max = ft_atoi(curr->value);
        curr = curr->next;
    }
    return max;
}

int ft_get_min_value(t_list *lst)
{
    int min;
    t_list *curr;

    min = ft_atoi(lst->value);
    curr = lst;
    while(curr)
    {
        if(ft_atoi(curr->value) < min)
            min = ft_atoi(curr->value);
        curr = curr->next;
    }

    return min;
    
}