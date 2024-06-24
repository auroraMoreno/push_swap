/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:28:08 by aumoreno          #+#    #+#             */
/*   Updated: 2024/06/24 18:22:49 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*utils that will handle stacks*/

int ft_lstsize(t_list *lst)
{
    t_list *curr;
    int len;
    
    curr = lst; 
    len = 0;
    while(curr)
    {
        len++;
        curr = curr->next;
    }
    return (len);
}

//repasar punteros empty
t_list *ft_lstnew(void *content)
{
    t_list *element;

    element = (t_list *)malloc(sizeof(t_list));
    if(!element)
        return (NULL);
    element->value = content;
    element->next = NULL;
    return(element);
}


// if only used here, remove index and set i=0 
t_list *ft_insert_initial(char *args[], int index)
{
    t_list *numbers;

    if(!args[index])
        return NULL;
    
    numbers = ft_lstnew((char *) args[index]);
    numbers->next = ft_insert_initial(args, ++index);
    return (numbers);
}

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    
    if(!*lst)
        return;
    while(*lst)
    {
        temp = (*lst)->next;
        if(del)
            del((*lst)->value);
        free(*lst);
        *lst = temp;   
    }
    // ft_lstclear(&(*lst)->next,del);
    // del((*lst)->value);
    // free(*lst);
    *lst = NULL;
            
}

int ft_issorted(t_list *numbers)
{
    t_list *curr; 

    curr = numbers;

    while(curr->next)
    {
        if(ft_atoi(curr->value) > ft_atoi(curr->next->value))
            return(0);
        curr = curr->next;
    }
    return (1);
}