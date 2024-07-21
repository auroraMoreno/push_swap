/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:09:00 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/22 00:22:54 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
    lo que hago esq primero intercambio 
    el primero con el ultimo
    y luego cuando el viejo ultimo está en el primero
    lo voy rotando hasta que se queda justo antes de llegar a la ulrima pos 
    lo que voy a hacer es coger el primer nodo e ir moviendolo hacia atrás 
    
*/
void ft_rotate(t_list *lst)
{
    t_list *first;
    t_list *curr; 
    void *aux;

    // encontrar el primer nodo

    first = lst; 

    // guardar el contenido del primer nodo para no perderlo
    // esto es porque el valor del primer nodo se sobreescribiría con el valro del segundo
    aux = first->value;
    
    // hacer bucle para ir intercambiando las pos
    // lo que voy a hacer es coger el primer nodo e ir moviendolo hacia atrás 
    curr = lst; 
    while(curr->next)
    {
        // coger el siguiente y ponerlo en el anterior
        //realmente solo estamos intercambiando valores so it's fine 
        curr->value = curr->next->value;
        curr = curr->next;        
    }
    //curr ahora fuera del bucle va a ser el ultimo nodo
    // por tanto sustituimos el valor del ultimo nodo por el del primero: 
    curr->value = aux; 
    
}

/*
Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
No hace nada si a está vacío
*/
void ft_rotate_a(t_list *a)
{

    if(!a || ft_lstsize(a) == 1)
        return;
    if(ft_lstsize(a) == 2)
        return (ft_swap_a(a));
    
    ft_rotate(a);

    ft_printf("ra\n");
}


void ft_rotate_b(t_list *b)
{
    if(!b || ft_lstsize(b) == 1)
        return;
    if(ft_lstsize(b) == 2)
        return (ft_swap_b(b));
    
    ft_rotate(b);

    ft_printf("rb\n");
}


void ft_rr(t_list *a, t_list *b)
{
    ft_rotate_a(a);
    ft_rotate(b);
    ft_printf("rr\n");
}


void ft_rotate_list(int *top_pos, int *bottom_pos, t_list **b)
{
    if(*top_pos <= *bottom_pos)
    {
        ft_rotate_b(*b);
        (*top_pos)--;
        (*bottom_pos)++;
    }
    else
    {
        ft_reverse_rotate_b(*b);
        (*top_pos)++;
        (*bottom_pos)--;
    }
}