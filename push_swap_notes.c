/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:11 by aumoreno          #+#    #+#             */
/*   Updated: 2024/05/15 16:53:45 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int x; // this would be the "info", the element fro mthe array 
	struct Node* next; // the pointer to the same type of element that we are in (so a Node) 
	// it is called next as it's really the next element in the linked list
	// IT IS VERY IMPORTANT to set the struct word as if not, when compiling, since Node doesn't exist yet, it will fail 
}Node;



int main()
{
	Node root; 
	root.x = 15;
	// first we dyamically allocated the memory:
	root.next = malloc(sizeof(Node)); // 
	root.next->x = -2; // now, instead of elem2.x we would have to use this syntaxis
	root.next->next = NULL;

	printf("First: %d\n", root.x);
	printf("Second: %d\n", root.next->x); //dereferencing this pointer to get the actual value 

	free(root.next); // as root.next has been allocated dyamically, it will not be auto deallocated so we have to free it (memory leak hehe)
	return (0);
}













void push_swap()
{
	// vamos a empezar pintando la lista de números que nos llegue por consola 
	
	// si solo se puede pasar un numero a la vez, habrá que guardarlo en una lista de integer 
	// no sé porque dudo probablemente vaya a tener que pasarla a una lista de ints

	// cambio to test ssh key 
}