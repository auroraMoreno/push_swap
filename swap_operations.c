/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:42:10 by aumoreno          #+#    #+#             */
/*   Updated: 2024/06/30 11:23:23 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Intercambia los dos primeros elementos (nodes) del stack a. 
El primero se vuelve el segundo y el segundo el primero
No hace nada si hay uno o menos elementos.
*/
void ft_swap_a(t_list *a)
{
    t_list *first; 
    t_list *second;
    void *aux; 
    
    if(ft_lstsize(a) <= 1)
        return;
    first = a; 
    second = a->next; //aqui tenemos el segundo nodo
    // ponemos le primero de a en el segundo
    aux = first->value; 
    first->value = second->value;
    second->value = aux;
    // el segundo dondeel primero
    ft_printf("sa\n");
}


void ft_swap_b(t_list *b)
{
    t_list *first; 
    t_list *second; 
    void *aux; 
    
    if(ft_lstsize(b) <= 1)
        return;
    
    first = b;
    second = b->next;
    
    aux = first->value;
    first->value = second->value;
    second->value = aux;

    ft_printf("sb\n");
}

void ft_ss(t_list *a, t_list *b)
{
    ft_swap_a(a);
    ft_swap_b(b);
    ft_printf("ss\n");
}