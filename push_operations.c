/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:36:38 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/22 00:53:28 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_insert_first(t_list **lst, t_list *new_value)
{
    t_list *curr;

    //if list has values
    if(*lst)
    {
        // pasamos el valor del primer nodo original a la var aux
        curr = *lst; 
        // asignamos el valor del nuevo primero en la primera pos
        *lst = new_value; // el valor del primero es el q viene por param
        //el q antes era primero becomes second
        new_value->next = curr;
    }
    //if it doesn't and it's the first value
    else
    {
        // si no habia otros elementos en la lista, ponemos en nuevo valor en el primero
         *lst = new_value;   
    }

}


// b = src
// a = dest
void ft_push(t_list **dest, t_list **src)
{
    t_list *head; //like the head
    t_list *new_first; //will be the new element 
    // find first element of b 
    // aactualizamos en el src para poner la nueva head
    head = (*src)->next; //el antiguo "segundo" ahora es el nuevo primero 
    // insertamos en la lista dest
        //creamos el nuevo elemento para la lista a
        //src es b entonces el new element tiene que ser el primero de b
    new_first = ft_lstnew((*src)->value);
    ft_insert_first(dest, new_first);
    // borramos en src ya no esté ese elemento
    ft_lst_del_elment(*src, NULL);
    *src = head; //update de src list to point to the new head 

    
}

/*
Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío
b => a
*/
// b = src
// a = dest 
void ft_pa(t_list  **a, t_list **b)
{    
    //check si b está vacío 
    if(!*b)
        return; // devuelve null i hope
    ft_push(a,b);
    //print operation; 
    ft_printf("pa\n");
}

/*
Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
estoy pasando el 1º de a => b, lo que tiene lo nuevo es b
entonces tengo que devolver b 
a => src 
b => dest 
*/
void ft_pb(t_list **a, t_list **b)
{
    if(!*a)
        return;
    ft_push(b,a);
    ft_printf("pb\n");
}
