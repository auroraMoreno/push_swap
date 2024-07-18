/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:30:23 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/18 22:28:36 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    ft_printf("starting\n");
    // declaramos los punteros
    t_list *a;       // we will store the numbers here
    t_list *b;       // this is empty
    char **str_data; // this is for when the numbers be coming like "..."
    int should_free;

    // comprobaciones errores
    /**
     * 2 o mas en argc
     * [1] not empty
     * (argv[1][0] checks if is the null character)
     */
    should_free = 0;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (ft_putendl_fd("Error", 2), 0);
    // tener en cuenta 2 casos
    /**
     * numeros sueltos
     * numeros entre " "
     */
    else if (argc == 2)
    {
        ft_printf("splitting\n");
        // esto significa q lo mas probable es q los numeros vengan asi "..."
        str_data = ft_split(argv[1], ' ');
        should_free = 1;
        ft_printf("end split");
    }
    else
    {
        ft_printf("not splitting\n");
        // aqui es si es más de dos, es decir vienen asi: 3 7 99 42
        str_data = argv + 1;
    }

    ft_printf("about to insert\n");

    /*guardar en stack A*/
    a = ft_insert_initial(str_data, 0);
    b = NULL;
    ft_printf("end insert\n");
    // GESTION DE ERRORES
    /**
     * cuando guardemos en stack a habrá que ver si:
     * vienen duplicados,
     * solo admita +,- o digits
     * integer overflow (usaremos longs) => argumentos superiores a un número entero
     *  */
    ft_error_checking(a);
    ft_printf("errors not found\n");
    // comprobar si está sorted
    
    if(ft_issorted(a) == 1)
    {
        // it it's ordered we success
        ft_printf("the list is sorted\n");
        exit(EXIT_SUCCESS);
    }

    // si no lo está we sort it (chunkos time)
    ft_printf("the list is not sorted\n");

    // depending if 2,3,4,5 or more 
    // if 2,3,4,5 then "hard code" if more the alg
    ft_select_alg(&a,&b);
    /* PUSHH!!!!! */
    // ft_printf("checking the push operation\n");
    // ft_pb(&a,&b);

    /* SWAPPING!!! */
    // ft_printf("going into the swap a op\n");
    // ft_swap_a(a);

    /* ROTATING!!!! */
    // ft_printf("going into the rotate a op\n");
    // ft_rotate_a(a);


    /* REVERSINGGG!!! */
    // ft_printf("going into the rotate a op\n");
    // ft_reverse_rotate_a(a);

    
    // // print the operations
        ft_printf("about to print the list a\n");
    // // printing the numbers;
        ft_print_list(a);
    // // ft_printf("about to print the list b\n");
    // // ft_print_list(b);
    // ft_printf("printed the list\n");

    // clean the whole thing up
    if (should_free == 1)
    {
        ft_free_arr(str_data); // not able to use free bc str is an array
        ft_printf("freed the str");
    }
    ft_printf("about to free\n"); //CHECK WITH VALGRIND
    ft_lstclear(&a, NULL);
    ft_lstclear(&b, NULL);
    ft_printf("freed mem");
    return(0);
}