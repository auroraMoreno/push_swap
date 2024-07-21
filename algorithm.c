/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:20:19 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/22 00:32:38 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int *ft_generate_segments(t_list *lst)
{
    int *segments; 
    int min;
    int max; 
    int number_segments;
    int interval_size;  
    int i;
    
    if(ft_lstsize(lst) <= 10)
        number_segments = 3;
    else if(ft_lstsize(lst) <= 100)
        number_segments = 7;
    else 
        number_segments = 10;
    min = ft_get_min_value(lst);
    max = ft_get_max_value(lst);
    interval_size = (max - min) / number_segments;
    segments = (int *)malloc((number_segments + 1) * sizeof(int));
    if(!segments)
        return (NULL);
    i=0;
    while(i < number_segments)
    {
        segments[i] = min + (i * interval_size);
        i++;
    }
    segments[i] = max + 1; 
    return (segments);
}
int ft_chunk_has_elements(t_list *a, int i, int *chunks)
{
    t_list *curr; 

    curr = a;
    while(curr)
    {
        if(ft_is_in_range(ft_atoi(curr->value), i, chunks))
            return (1);
        curr = curr->next; 
    }

    return (0);
}

int ft_move_to_b(t_list **a, t_list **b, int *chunks)
{
    int i;

    i = 0;
    while(*a)
    {
        while(ft_chunk_has_elements(*a, i, chunks))
        {
            if(ft_is_in_range(ft_atoi((*a)->value), i, chunks))
                ft_pb(a,b);
            else 
                ft_rotate_a(*a);
        }
        i++;
    }
    return(i);
}

void ft_move_to_a(t_list **a, t_list **b)
{
    int pos_max;
    int top_pos;
    int bottom_pos;

    while(*b)
    {
        while(ft_get_max_pos(*b))
        {
            pos_max = ft_get_max_pos(*b);
            top_pos = pos_max;
            bottom_pos = ft_lstsize(*b) - pos_max;
            ft_rotate_list(&top_pos, &bottom_pos, b);
        }
        ft_pa(a,b);
    }
}


void ft_do_alg(t_list **a, t_list **b)
{
    int *segments; 
    
    segments = ft_generate_segments(*a);
    //ahora tenemos que comprobar que lo que hay en list a 
    // e ir pasando por los segmentos hechos
    // comprobaremos a que rango pertenece
    // si el número que estamos analizando pertenece al rango en el que estamos lo pushearemos a => b 
    // de esta forma en b estarán ordenadas, luego pushearemos de vuelta a => A 
    ft_move_to_b(a,b,segments);
    ft_move_to_a(a,b);
    free(segments); // bc we use malloc in the generate segment method to allocate the segment pointer
}

