/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:50:36 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/05 02:33:15 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_get_last(t_list *lst)
{
    t_list *last;

    last = lst;
    if(!last)
        return (0);
    while(last->next)
        last = last->next;
    return(last);
}

// list example: 2,3,4,1
void ft_reserve_rotate(t_list *lst)
{
    t_list *last; 
    t_list *curr;
    void *aux_last;
    void *aux_first;   
    void *next;

    // encontrar el último nodo 
    last = ft_get_last(lst);
    // guardar le contenido del ultimo nodo para no perderlo
    aux_last = last->value;
    // también el del primero nodo por le mismo motivo
    // y para intercambiarlo al final
    aux_first = lst->value;
    // vamos a empezar le bucle en el segundo no 
    curr = lst->next;
    // hay q empezar en el segundo porque el primero lo cambiaremos al final
    // con el ultimo 
    while(curr->next)
    {
        next = curr->value; // guardamos el valor del actual
        // el valor actual se reemplazará por el valor aux_first
        // en la primera iter aux_first será el valor del primer nodo
        curr->value = aux_first; // aqui hemos intercambiado ya el segundo valor por el del primero
        // ahora aux será la variable next que contiene el valor de nodo actual
        aux_first = next; 
        // saltamos al siguiente nodo:
        curr = curr->next;
    }

    // el current va a ser el ultimo at this point
    // so we take the value of aux_fist y se lo pasanos
    // ya que el ultimo tiene que ser el primero
    curr->value = aux_first;
    // el primer valor del nodo de la lista va a ser el ultimo 
    lst->value = aux_last; 
    
    
}


/*
Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.

*/
void ft_reverse_rotate_a(t_list *a)
{

    // check if a si empty or something 
    if(!a || ft_lstsize(a) == 1)
        return;
    if(ft_lstsize(a) == 2)
        return ft_swap_a(a);
    
    ft_reserve_rotate(a);
    
    ft_printf("rra\n");
}


void ft_reverse_rotate_b(t_list *b)
{
        // check if a si empty or something 
    if(!b || ft_lstsize(b) == 1)
        return;
    if(ft_lstsize(b) == 2)
        return ft_swap_b(b);
    
    ft_reserve_rotate(b);
    
    ft_printf("rrb\n");
}

void ft_rrr(t_list *a, t_list *b)
{
    ft_reverse_rotate_a(a);
    ft_reserve_rotate(b);
    ft_printf("rrr\n");
}