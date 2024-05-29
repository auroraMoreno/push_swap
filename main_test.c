/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:22:42 by aumoreno          #+#    #+#             */
/*   Updated: 2024/05/17 13:31:33 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int argc, char* argv[])
{
    int i;
    (void)argc;
    i = 0;
    while(argv[i] != NULL)
    {
        ft_printf("argv[%d], %s\n",i,argv[i]);
        i++;
    }

    int result = 1;
    i = 1;
    while(i < argc)
    {
        result = result * ft_atoi(argv[i]);    
        i++;
    }

    ft_printf("Multiplication result: %d\n",result);
    return (0);
}