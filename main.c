/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:05:54 by aumoreno          #+#    #+#             */
/*   Updated: 2024/05/29 15:19:02 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//las operaciones de swap, les deberá de llegar tanto  el stacknumbers omo el stackaux  


// left to right 
void ft_insert_list(StackNumbers** root, int value)
{
    StackNumbers* new_node =  malloc(sizeof(StackNumbers));
    
    if(!new_node)
        return;

    new_node->next = NULL;
    new_node->x = value;

    // si la lista esta vacia:
    if(*root == NULL)
    {
        *root = new_node;
        return;
    }    

    StackNumbers *curr = *root;

    while(curr->next != NULL)
        curr = curr->next;

    curr->next = new_node;
}

// para ver como van poniendose los numeros 
void ft_print_list(StackNumbers* node)
{
    while(node != NULL)
    {
        ft_printf("%d\n", node->x);
        node = node->next;
    }
}


int main(int argc, char* argv[])
{
    
    StackNumbers* stack = NULL;
    
    // empezar en 1 bc el argv[0] es el nombre de exe 
    // mientras argv, empezando en 0, tenga cosas, lo inserto en una lista (ver insert_end)
    int i;
    (void)argc;
    i = 1;
    while(argv[i] != NULL)
    {
        // inserto en el stack 1
        ft_insert_list(&stack, ft_atoi(argv[i]));
        i++;
    }
    
    //we should probs free this at some point 
    ft_print_list(stack);
    return (0);
}