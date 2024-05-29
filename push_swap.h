/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno <aumoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:57:15 by aumoreno          #+#    #+#             */
/*   Updated: 2024/05/29 14:39:36 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct StackNumbers{
	int x;
	struct StackNumbers* next;
}StackNumbers;

typedef struct StackAux{
    int x;
    struct StackAux* next;
}StackAux;




int main();