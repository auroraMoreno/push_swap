/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:05:54 by aumoreno          #+#    #+#             */
/*   Updated: 2024/06/15 06:15:45 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// las operaciones de swap, les deberá de llegar tanto  el stacknumbers omo el stackaux

// insert at the begining of the list

void ft_insert_beggining(StackNumbers **tail, int value)
{
    StackNumbers *new_node = malloc(sizeof(StackNumbers));
    if (new_node == NULL)
        return;

    new_node->x = value;
    new_node->previous = NULL; // since it's going to become our new tail
    new_node->next = *tail;    // *tail gets the point (deref 1 gets the pointer)

    if(*tail != NULL)
    // change the previous pointer in tail to the new_node
        (*tail)->previous = new_node;
        
    // we set our tail to our new tail: 
    *tail = new_node; // y ahora le ponemos en el pointer de tail q es el new_node 
    /**
        tail is a pointer to a pointer to a Node.
        *tail gives you the Node* that tail is pointing to.
        (*tail)->previous accesses the previous member of the node that *tail points to.
        new_node is another Node*.
     */
}

// left to right (inserts at the end )
void ft_insert_list(StackNumbers **root, int value)
{
    StackNumbers *new_node = malloc(sizeof(StackNumbers));

    if (!new_node)
        return;

    new_node->next = NULL;
    new_node->x = value;

    // si la lista esta vacia:
    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    StackNumbers *curr = *root;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = new_node;
}

// para ver como van poniendose los numeros
void ft_print_list(StackNumbers *node)
{
    while (node != NULL)
    {
        ft_printf("%d\n", node->x);
        node = node->next;
    }
}

// to set a pointer double to null, we need a pointer to that pointer
void ft_deallocate(StackNumbers **tail, StackNumbers **head)
{
    // we check if our doubly linked lists are already empty:
    if (*tail == NULL || *head == NULL)
    {
        return;
    }

    // start at the second node and deallocate the previous node

    StackNumbers *curr = *tail;

    while (curr->next == NULL)
    {
        curr = curr->next;
        free(curr->previous);
    }

    // outside the loop we deallocate our last node
    free(curr);
    *tail = NULL;
    *head = NULL;
}

int main(int argc, char *argv[])
{

    StackNumbers *stackTail = NULL;
    StackNumbers *stackHead = stackTail; 

    // empezar en 1 bc el argv[0] es el nombre de exe
    // mientras argv, empezando en 0, tenga cosas, lo inserto en una lista (ver insert_end)
    int i;
    (void)argc;

    i = 1;
    while (argv[i] != NULL)
    {
        // inserto en el stack 1
        ft_insert_beggining(&stackTail, ft_atoi(argv[i]));
        i++;
    }

    // we should probs free this at some point
    ft_print_list(stackTail);

    ft_deallocate(&stackTail, &stackHead); // we would deallocate tail and head &
    return (0);
}