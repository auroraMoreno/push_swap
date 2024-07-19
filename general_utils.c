/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:52:34 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/19 17:40:51 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*util function to use in general*/

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
    
}

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

void ft_free_arr(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    arr = NULL;
}

int ft_strcmp(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 - *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void ft_print_list(t_list *numbers)
{
    if(!numbers)
        return;
    
    while(numbers != NULL)
    {
        ft_printf("%s\n", (char *)numbers->value);
        numbers = numbers->next;
    }
}
