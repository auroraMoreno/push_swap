/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:40:08 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/19 19:46:01 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_five(t_list **a, t_list **b)
{
    int min;
    
    min = ft_get_min_value(*a);
    if(ft_atoi(ft_get_last(*a)->value) == min)
        ft_reverse_rotate_a(*a);
    else
    {
        while(ft_atoi((*a)->value) != min)
            ft_rotate_a(*a);    
    }

    ft_pb(a,b);
    ft_sort_four(a,b);
    ft_pa(a,b);
}