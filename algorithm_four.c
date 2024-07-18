/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:11:26 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/18 22:33:26 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_min_value(t_list *a)
{
    int min;
    t_list *curr;

    min = ft_atoi(a->value);
    curr = a;
    while(curr)
    {
        if(ft_atoi(curr->value) < min)
            min = ft_atoi(curr->value);
        curr = curr->next;
    }

    return min;
    
}

void ft_sort_four(t_list **a, t_list **b)
{
    int min;
    
    min = ft_get_min_value(*a);
    while(ft_atoi((*a)->value) != min)
        ft_rotate_a(*a);
    
    ft_pb(a,b);
    ft_sort_three(a,b);
    ft_pa(a,b);
}