/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_notes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:11 by aumoreno          #+#    #+#             */
/*   Updated: 2024/05/26 12:08:30 by aumoreno         ###   ########.fr       */
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

// a Node** (double pointer) is a pointer to another pointer 
// so it's two arrows, the first arrow points to the second arrow which is another pointer (Arrow) which points
// to another node (the root node)
void insert_end(Node** root, int value)
{
	// get to the last node and change next pointer to be a pointer to the newly created node
	// 1. Node creation:
	Node* new_node = malloc(sizeof(Node)); //volvemos a alocar memoryia para el nuevo nodo
	if(!new_node)
		return;
	new_node->next = NULL; //since we are adding at the end, the next of our new node should be NULL
	new_node->x=value; 

	// when we deref 1 (root), there is no prob bc  root actually has value (another address)
	// but when we deref twice for example *root, then that is pointing to null 
	if(*root == NULL)
	{
		*root = new_node; 
		return;
	}
	
	// 2. iterate thru the list to get to the last node: 
	Node *curr = *root;  //since root is a double pointer i only dereference it onse so that i get to that arrow that points to the node itself
	// AQUIE ARRIBA ESTAMO DEREF A ROOT COGIENDO EL VALOR QUE TENGA PERO ES UN DOUBLE POINTER
	// ES DECIR CUANDO PONEMOS *root ESTAMOS DICIENDO QUE VAYA A LA MEMORY ADDRES QUE TENGA Y COJA EL VALOR PERO COMO ES UN DOBLE PUNTERO
	// CUANDO SIGA LA PRIMERA MEMROY ADRESS SE VA A ENCONTRAR QUE EL VALOR ES OTRA MEMORY ADDRESS por eso curr tiene que ser otro puntero 
	//y por eso aqui debajo en el while tenemos que usar -> PARA DEREF Y QUE VAYA A POR EL VALOR DE NEXT (q en este caso como next es un puntero tambien tendrá una memory address)
	while(curr->next != NULL) 
	//also changed this bc we don't want curr to be null bc if its null we can't really change anything we wan't that after the loop, 
	//we want to end up with curr being the last_node
	{
		curr = curr->next; //aqui le cambiamos el valor de *curr por la memory address que sea la del siguiente nodo 
	}
	// after this loop we will know that curr->next is null (as curr will be the last node) soo 
	// we substitute that with the new_node 
	curr->next = new_node; //the address to our new node (as it's still a pointer) 
	
}

void deallocate(Node** root)
{
	// we are taking a double pointer to root, so that at the end we can set the root to NULL so that we know that the list does not exist anymore
	// if we did:
	// free(*root); // we will be deallocating the first node, but the rest of the nodes would still be allocated but they won't be accesible 
	// you want to go to every single pointer and deallocate them one by one 
	// so a linked list always iterates from left to right 
	// but we have to dealloc in a way where  we don't destroy our own memory
	Node* curr = *root; 
	while(curr != NULL)
	{
	// we are going to have 2 variables, one with the node we want to dealloc and another with the next node 
		Node* aux = curr; 
		curr = curr->next; 
		free(aux);
		// now even if we enter with one element, that first element is going to become aux and curr will become null as curr->next is null
	}
	
	*root = NULL; //the value (*) of root is now null 
	//we have to do this, bc root* still has that value BUT the memory is no longer allocated 
}

int main()
{
	//small check in case Node is empty, doesn't have an initial value: 
	Node* root = NULL; 
	
	
	// // we want to change the way root is stored in memory: 
	// // Node root; // this is on the stack (bc is not in a malloc )
	// // but due to the fact that we need a ** for insert_end, we will have to dynamically allocate it 
	// // we will change this to a pointer to do so:
	// // Node *root = malloc(sizeof(Node)); // estoy alocando aqui uuna serie de memoria para root (dimicamente)
	// // // arriba we have an arrow to a node (a memory addres, a pointer, to a Node)
	// // if(root == NULL)
	// // {
	// // 	return (NULL);
	// // }
	
	// root->x = 15; //aqui le estoy dando el valor
	// // y aqui debajo le estaria mandando otra direccion de memoria bc next es un puntero PERO como queremos que sea el ultimo le ponemos null 
	// root->next = NULL; // we want to start with only a single node inside our list 
	// // we change from . to -> as we have now to derefence it 

	// we need to send to the function a double pointer to Node (which is our root)
	// we have the Node* which is on the stack, so the arrow is on the stack, BUT the its value is on the heap 
	// so it's dynamically allocated
	// but what i want to send to function is the place in memory where the Node* arrow is stored 
	// so: 
	insert_end(&root, -2); // cuando pasamos una address de un puntero tiene que recibirla una doble puntero (usually)
	insert_end(&root, 11);

	Node *curr = root; 
	// root is not enough bc root is on the stack, so we need to get the address of that bc curr is actually a pointer to a node 
	// so it's not curr (like root) is *curr, so its a Node pointer, which contains the adrres to the next 
	// notice how in Node the next is a pointer 
	// that's why we can do curr != NULL and is not need to do: curr->next bc in the curr we assigned &root (Which is the address, which is a pointer)

	while(curr != NULL)
	{
		// overwritting the current pointer to be the next block up
		printf("%d\n", curr->x);
		curr = curr->next; 
	}

	deallocate(&root);
	return (0);
}













void push_swap()
{
	// vamos a empezar pintando la lista de números que nos llegue por consola 
	
	// si solo se puede pasar un numero a la vez, habrá que guardarlo en una lista de integer 
	// no sé porque dudo probablemente vaya a tener que pasarla a una lista de ints

	// cambio to test ssh key 
}